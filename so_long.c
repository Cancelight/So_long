/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:46:32 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/24 14:13:33 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

void	def_img(t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "./xpmg/sol.xpm", &x,&y);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "./xpmg/fl.xpm", &x,&y);
	data->hero_img = mlx_xpm_file_to_image(data->mlx, "./xpmg/st.xpm", &x,&y);
	data->collect_img = mlx_xpm_file_to_image(data->mlx, "./xpmg/pn.xpm", &x,&y);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./xpmg/sky.xpm", &x, &y);
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
			if(data -> map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img, x * 64, y * 64);
			else if (data -> map[y][x] != '1' && data -> map[y][x] != '\n')
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
	mlx_put_image_to_window(data->mlx, data->win, data->exit_img, data->e_loc[1] * 64, data->e_loc[0] * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->hero_img, data->p_loc[1] * 64, data->p_loc[0] * 64);
	while (++y < data -> y_max)
	{
		x = 0;
		while (data -> map[y][++x])
		{
			if (data -> map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->collect_img, x * 64, y * 64);
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
	data.win = mlx_new_window(data.mlx, (data.x_max - 1) * 64, data.y_max * 64, "Project");
	def_img(&data);
	background(&data);
	up_layer(&data);
	mlx_key_hook(data.win, direct_moves, &data);
	mlx_loop(data.mlx);
}
