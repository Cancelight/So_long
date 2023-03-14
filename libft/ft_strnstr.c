/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:58:24 by bkiziler          #+#    #+#             */
/*   Updated: 2022/11/15 19:15:55 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	flag;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (!needle_len)
		return ((char *)(haystack));
	else if (len == 0 || !haystack[0])
		return (0);
	while (i < len)
	{
		n = i;
		flag = 0;
		while ((*(needle + flag) == *(haystack + n)) && *(needle + flag) != '\0'
			&& n++ < len)
			flag++;
		if (flag == needle_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
