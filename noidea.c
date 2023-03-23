/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noidea.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:46:32 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/23 16:35:32 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

void	def_img(t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	data -> wall_img = mlx_xpm_file_to_image(data -> mlx, "./xpm_images/soldier.xpm", &x,&y);
	data -> floor_img = mlx_xpm_file_to_image(data -> mlx, "./xpm_images/floor.xpm", &x,&y);
	data -> hero_img = mlx_xpm_file_to_image(data -> mlx, "./xpm_images/sokrates.xpm", &x,&y);
	data -> collect_img = mlx_xpm_file_to_image(data -> mlx, "./xpm_images/poison.xpm", &x,&y);
}

void	background(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	data -> win = mlx_new_window(data -> mlx, (data -> x_max - 1) * 64, data -> y_max * 64, "Project");
	while (++y < data -> y_max)
	{
		x = -1;
		while (data -> map[y][++x])
		{
			if(data -> map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img, x * 64, y * 64);
			else if (data -> map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->floor_img, x * 64, y * 64);
		}
	}
}

void	up_layer(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++y < data -> y_max)
	{
		x = 0;
		while (data -> map[y][++x])
		{
			if(data -> map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->hero_img, x * 64, y * 64);
			else if (data -> map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->collect_img, x * 64, y * 64);
			else if (data -> map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img, x * 64, y * 64);
		}
	}
}

int	main(void)
{
	t_data	data;

	if (map_size(&data) == -1 )
	{
		perror("Invalid map\n");
		exit(1);
	}
	data.mlx = mlx_init();
	def_img(&data);
	background(&data);
	up_layer(&data);
	mlx_key_hook(data.win, direct_moves, &data);
	mlx_loop(data.mlx);
}
