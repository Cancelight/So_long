/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:14:54 by bkiziler          #+#    #+#             */
/*   Updated: 2022/11/09 17:12:24 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	u;
	size_t			i;

	u = c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = u;
		i++;
	}
	return (b);
}
