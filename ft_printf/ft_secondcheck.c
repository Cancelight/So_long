/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secondcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:45:31 by bkiziler          #+#    #+#             */
/*   Updated: 2022/12/07 13:48:31 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_secondcheck(va_list args, int *count, const char *str)
{
	if (*str == 'x')
		ft_puthexal(va_arg(args, int), count);
	else if (*str == 'X')
		ft_puthexau(va_arg(args, int), count);
	else if (*str == 'u')
		ft_unint(va_arg(args, unsigned int), count);
	else if (*str == 'p')
	{
		write(1, "0x", 2);
		*count += 2;
		ft_putpointer(va_arg(args, unsigned long), count);
	}
}
