/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:12:18 by bkiziler          #+#    #+#             */
/*   Updated: 2022/12/07 13:32:38 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexau(unsigned int n, int *i)
{
	if (n > 15)
	{
		ft_puthexau(n / 16, i);
		ft_puthexau(n % 16, i);
	}
	else if (n < 16)
		*i += ft_putchar("0123456789ABCDEF"[n]);
}

void	ft_puthexal(unsigned int n, int *i)
{
	if (n > 15)
	{
		ft_puthexal(n / 16, i);
		ft_puthexal(n % 16, i);
	}
	else if (n < 16)
		*i += ft_putchar("0123456789abcdef"[n]);
}

void	ft_unint(unsigned int n, int *i)
{
	if (n > 9)
	{
		ft_unint(n / 10, i);
		ft_unint(n % 10, i);
	}
	else if (n < 10)
		*i += ft_putchar(n + '0');
}

void	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*i += 11;
	}
	else if (n < 0)
	{
		*i += ft_putchar('-');
		n = n * (-1);
		ft_putnbr(n, i);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, i);
		ft_putnbr(n % 10, i);
	}
	else if (n < 10)
		*i += ft_putchar(n + '0');
}

void	ft_putpointer(unsigned long n, int *i)
{
	if (n > 15)
	{
		ft_putpointer(n / 16, i);
		ft_putpointer(n % 16, i);
	}
	else if (n < 16)
		*i += ft_putchar("0123456789abcdef"[n]);
}
