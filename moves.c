/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:46:36 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/23 15:15:39 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

void direct_moves(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		step_count(up_move(data));
	else if (keycode == S || keycode == DOWN)
		step_count(down_move(data));
	else if (keycode == D || keycode == RIGHT)
		step_count(right_move(data));
	else if (keycode == A || keycode == LEFT)
		step_count(left_move(data));
	else if (keycode == ESC)
		mlx_destroy_window(data -> mlx, data -> win);
	return(0);
}

int	up_move(t_data *data)
{
	int	x;
	int	y;

	x = data -> p_loc[1];
	y = data -> p_loc[0];
	if ((data -> map[y + 1][x] == '1') || (data -> map[y + 1][x] == 'E' && data -> collect != 0))
		return (-1);
	else if (data -> map[y + 1][x] == '0')
	{
		data -> map[y][x] = '0';
		data -> map[y + 1][x] = 'P';
		gen_img(data);
	}
	else if (data -> map[y + 1][x] == 'C')
	{
		data -> map[y][x] = '0';
		data -> map[y + 1][x] = 'P';
		data -> collect--;
		gen_img(data);
	}
	else if (data -> map[y + 1][x] == 'E' && data -> collect == 0)
		// exit game
}

int	down_move(t_data *data)
{
	int	x;
	int	y;

	x = data -> p_loc[1];
	y = data -> p_loc[0];
	if ((data -> map[y - 1][x] == '1') || (data -> map[y + 1][x] == 'E' && data -> collect != 0))
		return (-1);
	else if (data -> map[y - 1][x] == '0')
	{
		data -> map[y][x] = '0';
		data -> map[y - 1][x] = 'P';
		gen_img(data);
	}
	else if (data -> map[y - 1][x] == 'C')
	{
		data -> map[y][x] = '0';
		data -> map[y - 1][x] = 'P';
		data -> collect--;
		gen_img(data);
	}
	else if (data -> map[y - 1][x] == 'E' && data -> collect == 0)
		// exit game
}

int	right_move(t_data *data)
{
	int	x;
	int	y;

	x = data -> p_loc[1];
	y = data -> p_loc[0];
	if ((data -> map[y][x + 1] == '1') || (data -> map[y][x + 1] == 'E' && data -> collect != 0))
		return (-1);
	else if (data -> map[y][x + 1] == '0')
	{
		data -> map[y][x] = '0';
		data -> map[y][x + 1] = 'P';
		gen_img(data);
	}
	else if (data -> map[y][x + 1] == 'C')
	{
		data -> map[y][x] = '0';
		data -> map[y][x + 1] = 'P';
		data -> collect--;
		gen_img(data);
	}
	else if (data -> map[y][x + 1] == 'E' && data -> collect == 0)
		// exit game
}

int	left_move(t_data *data)
{
	int	x;
	int	y;

	x = data -> p_loc[1];
	y = data -> p_loc[0];
	if ((data -> map[y][x - 1] == '1') || (data -> map[y][x - 1] == 'E' && data -> collect != 0))
		return (-1);
	else if (data -> map[y][x - 1] == '0')
	{
		data -> map[y][x] = '0';
		data -> map[y][x - 1] = 'P';
		gen_img(data);
	}
	else if (data -> map[y][x - 1] == 'C')
	{
		data -> map[y][x] = '0';
		data -> map[y][x - 1] = 'P';
		data -> collect--;
		gen_img(data);
	}
	else if (data -> map[y][x - 1] == 'E' && data -> collect == 0)
		// exit game
}


void	gen_img(t_data *data)
{
	mlx_destroy_window(data -> mlx, data -> win);
	background(data);
	up_layer(data);
}
