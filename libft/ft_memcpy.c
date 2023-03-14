/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:56:04 by bkiziler          #+#    #+#             */
/*   Updated: 2022/11/09 17:13:05 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (!src && !dst)
		return (0);
	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	while (i < n)
	{
			a[i] = b[i];
			i++;
	}
	return (a);
}
