/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:49:44 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/23 15:13:28 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

int	chr_check(t_data *data, int y_size)
{
	int		y;
	char	*a;

	y = -1;
	while (++y < y_size)
	{
		a = ft_strtrim(data -> map[y], "CP01E");
		if (!(a[0] == '\n' && a[1] == '\0'))
			return (-1);
	}
	free(a);
	return (0);
}

void	ple_loc(int y_size, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++y < y_size)
	{
		x = 0;
		while (data -> map[y][++x])
		{
			if (data -> map[y][x] == 'P')
			{
				data -> p_loc[0] = y;
				data -> p_loc[1] = x;
				return;
			}
		}
	}
}

void	step_count(int ret)
{
	static int step;

	if (ret == 1)
	{
		step++;
		ft_printf("%d", step);
	}
}
