/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:46:32 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/31 15:31:11 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

void	def_img(t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	data->wall_img = mlx_xpm_file_to_image(data->mlx, SOLXPM, &x, &y);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, FLXPM, &x, &y);
	data->hero_img = mlx_xpm_file_to_image(data->mlx, HRXPM, &x, &y);
	data->collect_img = mlx_xpm_file_to_image(data->mlx, PNXPM, &x, &y);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, SKYXPM, &x, &y);
}

void	background(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < data -> y_max)
	{
		x = -1;
		while (data -> map[y][++x])
		{
			if (data -> map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img, \
				x * 64, y * 64);
			else if (data -> map[y][x] != '1' && data -> map[y][x] != '\n')
				mlx_put_image_to_window(data->mlx, data->win, data->floor_img, \
				x * 64, y * 64);
		}
	}
}

void	up_layer(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->exit_img, \
	data->e_loc[1] * 64, data->e_loc[0] * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->hero_img, \
	data->p_loc[1] * 64, data->p_loc[0] * 64);
	while (++y < data -> y_max)
	{
		x = 0;
		while (data -> map[y][++x])
		{
			if (data -> map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, \
				data->collect_img, x * 64, y * 64);
		}
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		perror("Invalid argument count");
		exit(0);
	}
	name_check(&data, av[1]);
	if (map_size(&data) == -1)
	{
		system("leaks so_long");
		perror("Invalid map\n");
		exit(0);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (data.x_max - 1) * 64, \
	data.y_max * 64, "so_long");
	def_img(&data);
	background(&data);
	up_layer(&data);
	mlx_hook(data.win, 17, 0, exit_game, &data);
	mlx_hook(data.win, 2, 1L << 0, direct_moves, &data);
	mlx_loop(data.mlx);
}
