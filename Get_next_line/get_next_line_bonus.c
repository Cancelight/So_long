/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:37:04 by bkiziler          #+#    #+#             */
/*   Updated: 2023/02/01 11:40:14 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*red[256];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	red[fd] = read_function(fd, red[fd]);
	if (!red[fd])
		return (NULL);
	str = apart_line(red[fd]);
	red[fd] = trim(red[fd]);
	return (str);
}

char	*trim(char *red)
{
	char	*temp;
	int		i;

	i = 0;
	while (red[i] && red[i] != '\n')
		i++;
	if (!red[i])
	{
		free(red);
		return (NULL);
	}
	i++;
	temp = ft_substr(red, i, (ft_strlen(red) - i));
	if (!temp)
		return (NULL);
	free(red);
	return (temp);
}

char	*apart_line(char *red)
{
	char	*str;
	int		i;

	i = 0;
	if (!*(red + i))
		return (NULL);
	while (red[i] != '\n' && red[i] != '\0')
		i++;
	if (red[i] == '\n')
		str = ft_substr(red, 0, i + 1);
	else
		str = ft_substr(red, 0, i);
	if (!str)
		return (NULL);
	return (str);
}

char	*read_function(int fd, char *red)
{
	char	*str;
	int		eof;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	eof = 1;
	while (!ft_strchr(red, '\n') && eof != 0)
	{
		eof = read(fd, str, BUFFER_SIZE);
		if (eof == -1)
		{
			free(str);
			free(red);
			return (NULL);
		}
		str[eof] = '\0';
		red = ft_strjoin(red, str);
	}
	free(str);
	return (red);
}
