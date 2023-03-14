/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:36:57 by bkiziler          #+#    #+#             */
/*   Updated: 2022/12/07 13:45:00 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		a;
	int		*countc;

	va_start(arguments, str);
	a = 0;
	countc = &a;
	while (*str != '\0')
	{
		if (*str != '%' && *str != '\0')
			a += ft_putchar(*str);
		else
		{
			str++;
			ft_check(arguments, countc, str);
			ft_secondcheck(arguments, countc, str);
		}
		str++;
	}
	va_end(arguments);
	return (a);
}
