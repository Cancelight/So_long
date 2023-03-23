/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oslo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:01:24 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/23 14:53:58 by bkiziler         ###   ########.fr       */
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
#include <fcntl.h>
#include "./libft/libft.h"
#include "./Get_next_line/get_next_line.h"
#include "./Printf/ft_printf.h"

typedef struct	s_data {
	void		*wall_img;
	void		*floor_img;
	void		*hero_img;
	void		*collect_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			*p_loc; // y, x
	void		*mlx;
	void		*win;
	char 		**map;
	int			collect;
	int			y_max;
	int			x_max;
}				t_data;

int		up_move(t_data *data);
int		down_move(t_data *data);
int		left_move(t_data *data);
int		right_move(t_data *data);
int		direct_moves(int keycode, t_data *data);
void	def_img(t_data *data);
void	background(t_data *data);
int		map_size(t_data *data);
int		read_map(int x, int y, t_data *data);
int		map_wall(int y_size, t_data *data);
int		pe_check(int y_size, int c, t_data *data);
int		chr_check(t_data *data, int y_size);
void	ple_loc(int y_size, t_data *data);
void	up_layer(t_data *data);
void	gen_img(t_data *data);

#endif
