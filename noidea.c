/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noidea.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:46:32 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/20 21:22:35 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

void	background(t_vars *vars, t_data *img)
{
	int x;
	int y;

	mlx_clear_window(vars->mlx, vars->win);
	for (y = 64; y < 64 * 6; y+=64)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall_img, 0,y);
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall_img, 64*9,y);
	}
	for(x = 0; x<64*10; x+=64)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall_img, x, 64*5);
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall_img, x,0);
	}
	for (y = 64; y<64*5; y +=64)
	{
		for(x=64; x<64*9; x+=64)
			mlx_put_image_to_window(vars->mlx, vars->win, img->floor_img, x, y);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->collect_img, 64,64);
}

void	def_img(t_vars *vars, t_data *img)
{
	int x;
	int y;

	x=64;
	y=64;
	img->wall_img = mlx_xpm_file_to_image(vars->mlx, "./xpm_images/soldier.xpm", &x,&y);
	img->floor_img = mlx_xpm_file_to_image(vars->mlx, "./xpm_images/floor.xpm", &x,&y);
	img->hero_img = mlx_xpm_file_to_image(vars->mlx, "./xpm_images/sokrates.xpm", &x,&y);
	img-> collect_img = mlx_xpm_file_to_image(vars->mlx, "./xpm_images/poison.xpm", &x,&y);
	//first location of hero might be put there.
}

int	main(void)
{
	t_data	img;
	t_vars	vars;

	map_size();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 64*6, "Project");
	def_img(&vars, &img);
	background(&vars, &img);
	//mlx_key_hook(vars.win, direct_moves, &vars);
	mlx_loop(vars.mlx);
}
/*mapin txt olduğunu düşünürsek gnl ile okutup pointera aktarıp hareket ettikçe analitik
düzlem değişimi ve check hakimiyetini sağlarız.*/
