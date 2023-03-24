/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:36:34 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/23 16:50:37 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

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

char	*ft_strtrim(char *s1, char *set)
{
	char	*ptr;
	int	n;

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

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int		s1;
	int	i;

	i = 0;
	s1 = ft_strlen(src);
	if (!dstsize)
		return (s1);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s1);
}
