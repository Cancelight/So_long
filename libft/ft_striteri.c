/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:14:50 by bkiziler          #+#    #+#             */
/*   Updated: 2022/11/16 14:07:18 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && !(s == NULL))
	{
		(*f)(i, &s[i]);
		i++;
	}
}
