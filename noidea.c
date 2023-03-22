/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noidea.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:46:32 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/21 17:59:12 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

void	background(t_data *data)
{
	int x;
	int y;

	mlx_clear_window(data->mlx, data->win);
	for (y = 64; y < 64 * 6; y+=64)
	{
		mlx_put_image_to_window(data->mlx, data->win, img->wall_img, 0,y);
		mlx_put_image_to_window(data->mlx, data->win, img->wall_img, 64*9,y);
	}
	for(x = 0; x<64*10; x+=64)
	{
		mlx_put_image_to_window(data->mlx, data->win, img->wall_img, x, 64*5);
		mlx_put_image_to_window(data->mlx, data->win, img->wall_img, x,0);
	}
	for (y = 64; y<64*5; y +=64)
	{
		for(x=64; x<64*9; x+=64)
			mlx_put_image_to_window(data->mlx, data->win, img->floor_img, x, y);
	}
	mlx_put_image_to_window(data->mlx, data->win, img->collect_img, 64,64);
}

void	def_img(t_data *data)
{
	int x;
	int y;

	x=64;
	y=64;
	img->wall_img = mlx_xpm_file_to_image(data->mlx, "./xpm_images/soldier.xpm", &x,&y);
	img->floor_img = mlx_xpm_file_to_image(data->mlx, "./xpm_images/floor.xpm", &x,&y);
	img->hero_img = mlx_xpm_file_to_image(data->mlx, "./xpm_images/sokrates.xpm", &x,&y);
	img-> collect_img = mlx_xpm_file_to_image(data->mlx, "./xpm_images/poison.xpm", &x,&y);
	//first location of hero might be put there.
}

int	main(void)
{
	t_data	data;


	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 640, 64*6, "Project");
	if (map_size(&data) == -1 )
	{
		mlx_destroy_window(data.mlx, data.win);
		exit;
	}
	def_img(&data);
	background(&data);
	//mlx_key_hook(data.win, direct_moves, &data);
	mlx_loop(data.mlx);
}
