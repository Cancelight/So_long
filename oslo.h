/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oslo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:01:24 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/21 18:12:16 by bkiziler         ###   ########.fr       */
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
	t_location	*loc;
	void		*mlx;
	void		*win;
	char 		**map;
}				t_data;

typedef struct s_location{
	int	*p_loc;
	int	*c_xloc;
	int	*c_yloc;
}				t_location;

int		up_move(t_vars *vars);
int		down_move(t_vars *vars);
int		left_move(t_vars *vars);
int		right_move(t_vars *vars);
int		direct_moves(int keycode, t_vars *vars);
void	def_img(t_data *data);
void	background(t_data *data);
int		map_size(t_data *data);
int		read_map(int x, int y, t_data *data);
int		map_wall(int y_size, t_data *data);
int		pe_check(int y_size, int c, t_data *data);
void	col_loc(int count, int y_size, t_data *data);
int		chr_check(t_data *data, int y_size);
void	col_loc(int count, int y_size, t_data *data);
void	pl_loc(int y_size, t_data *data);

#endif
