/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oslo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:01:24 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/14 21:44:01 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSLO_H
# define OSLO_H

# define W	13
# define S	1
# define A	0
# define D	2
# define UP	126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ESC 53

#include "minilibx/mlx.h"
#include <stdio.h> // for perror
#include <stdlib.h> // for exit
#include <string.h> // for strerrror

typedef struct	s_data {
	void	*wall_img;
	void	*floor_img;
	void	*hero_img;
	void	*collect_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int		up_move(t_vars *vars);
int		down_move(t_vars *vars);
int		left_move(t_vars *vars);
int		right_move(t_vars *vars);
int		direct_moves(int keycode, t_vars *vars);
void	def_img(t_vars *vars, t_data *img);
void	background(t_vars *vars, t_data *img);

#endif
