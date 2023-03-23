/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:31:56 by bkiziler          #+#    #+#             */
/*   Updated: 2022/12/07 13:34:39 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(va_list args, int *count, const char *str)
{
	if (*str == '%')
	{
		*count += ft_putchar('%');
	}
	else if (*str == 'c')
	{
		*count += ft_putchar(va_arg(args, int));
	}
	else if (*str == 's')
	{
		*count += ft_printstr(va_arg(args, char *));
	}
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), count);
	return ;
}
