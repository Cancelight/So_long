/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:46:36 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/24 16:30:27 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

int	direct_moves(int keycode, t_data *data)
{
	int	x;
	int	y;

	y = data -> p_loc[0];
	x = data -> p_loc[1];
	if (keycode == W || keycode == UP)
		step_count(move_check(data, y - 1, x));
	else if (keycode == S || keycode == DOWN)
		step_count(move_check(data, y + 1, x));
	else if (keycode == D || keycode == RIGHT)
		step_count(move_check(data, y, x + 1));
	else if (keycode == A || keycode == LEFT)
		step_count(move_check(data, y, x - 1));
	else if (keycode == ESC)
		exit_game(data, 0);
	return (0);
}

int	move_check(t_data *data, int y, int x)
{
	int	a;
	int	b;

	a = data -> p_loc[0];
	b = data -> p_loc[1];
	if (data -> map[y][x] == '1')
		return (-1);
	else if (data -> map[y][x] == '0')
	{
		data -> map[a][b] = '0';
		data -> map[y][x] = 'P';
	}
	else if (data -> map[y][x] == 'C')
	{
		data -> map[a][b] = '0';
		data -> map[y][x] = 'P';
		data -> collect--;
	}
	else if (data -> map[y][x] == 'E' && data->collect == 0)
		exit_game(data, 0);
	exit_check(data, y, x);
	gen_img(data, x, y);
	return (1);
}

void	exit_check(t_data *data, int y, int x)
{
	int	a;
	int	b;

	if (data -> map[y][x] == 'E')
	{
		a = data -> p_loc[0];
		b = data -> p_loc[1];
		data -> map[a][b] = '0';
	}
	else
		data->map[data->e_loc[0]][data->e_loc[1]] = 'E';
}
