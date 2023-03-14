/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbasic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:35:28 by bkiziler          #+#    #+#             */
/*   Updated: 2022/12/07 13:42:57 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int		ret;
	char	c;

	ret = 0;
	if (s == NULL)
		return (ft_printstr("(null)"));
	while (*s)
	{
		c = *s++;
		write(1, &c, 1);
		ret++;
	}
	return (ret);
}

int	ft_strlength(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
