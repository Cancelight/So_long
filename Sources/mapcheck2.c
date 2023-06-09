/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:49:44 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/31 15:37:24 by bkiziler         ###   ########.fr       */
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
		free(a);
	}
	return (0);
}

void	ple_loc(int y_size, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data -> p_loc = malloc(sizeof(int) * 2);
	data -> e_loc = malloc(sizeof(int) * 2);
	while (++y < y_size)
	{
		x = 0;
		while (data -> map[y][++x] != '\n')
		{
			if (data -> map[y][x] == 'P')
			{
				data -> p_loc[0] = y;
				data -> p_loc[1] = x;
			}
			else if (data->map[y][x] == 'E')
			{
				data -> e_loc[0] = y;
				data -> e_loc[1] = x;
			}
		}
	}
}

void	step_count(int ret)
{
	static int	step;

	if (ret == 1)
	{
		step++;
		ft_printf("%d\n", step);
	}
}

void	gen_img(t_data *data, int x, int y)
{
	data -> p_loc[1] = x;
	data -> p_loc[0] = y;
	mlx_clear_window(data -> mlx, data -> win);
	background(data);
	up_layer(data);
}

int	exit_game(t_data *data)
{
	mlx_destroy_window(data -> mlx, data -> win);
	exit(0);
	return (0);
}
