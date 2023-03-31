/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validPath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:27 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/31 15:40:39 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

int	valid_path(t_data *data, int y, int x)
{
	if (data->temp[y][x + 1] && data->temp[y][x + 1] != '1' && \
	data->temp[y][x + 1] != '-')
		checkc(data, y, x + 1);
	if (data->temp[y - 1][x] && data->temp[y - 1][x] != '1' && \
	data->temp[y - 1][x] != '-')
		checkc(data, y - 1, x);
	if (data->temp[y][x - 1] && data->temp[y][x - 1] != '1' && \
	data->temp[y][x - 1] != '-')
		checkc(data, y, x - 1);
	if (data->temp[y + 1][x] && data->temp[y + 1][x] != '1' && \
	data->temp[y + 1][x] != '-')
		checkc(data, y + 1, x);
	return (data->count == data -> collect + 1);
}

void	checkc(t_data *data, int y, int x)
{
	if (data->temp[y][x] == 'E' || data->temp[y][x] == 'C')
			data->count++;
	data->temp[y][x] = '-';
	valid_path(data, y, x);
}

void	name_check(t_data *data, char *str)
{
	char	*ch;
	int		i;
	int		fd;

	fd = open(str, O_RDWR, 0777);
	i = ft_strlen(str) - 1;
	ch = "reb.";
	while (*ch)
	{
		if (str[i] != *ch || (*ch && i < 0) || fd < 0)
		{
			perror("Invalid file\n");
			exit(0);
			return ;
		}
		ch++;
		i--;
	}
	close(fd);
	i = ft_strlen(str);
	data->fname = malloc(sizeof(char) * (i + 2));
	ft_strlcpy(data->fname, str, i + 2);
}
