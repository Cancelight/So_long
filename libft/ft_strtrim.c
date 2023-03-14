/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:19:57 by bkiziler          #+#    #+#             */
/*   Updated: 2022/11/16 16:54:02 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char c, char const *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (c == ptr[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	n;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (check (*s1, set) && s1)
		s1++;
	n = ft_strlen(s1);
	while (check (s1[n - 1], set) && n != 0)
		n--;
	ptr = (char *)malloc(sizeof(char) *(n + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, n + 1);
	return (ptr);
}
