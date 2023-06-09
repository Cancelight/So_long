/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oslo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:01:24 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/31 15:19:59 by bkiziler         ###   ########.fr       */
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

# define FLXPM "./textures/floor.xpm"
# define SOLXPM "./textures/soldier.xpm"
# define HRXPM "./textures/hero.xpm"
# define SKYXPM "./textures/sky.xpm"
# define PNXPM "./textures/poison.xpm"

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_data {
	void		*wall_img;
	void		*floor_img;
	void		*hero_img;
	void		*collect_img;
	void		*exit_img;
	int			*p_loc;
	int			*e_loc;
	void		*mlx;
	void		*win;
	char		**map;
	char		**temp;
	int			collect;
	int			count;
	int			y_max;
	int			x_max;
	char		*fname;
}				t_data;

int		move_check(t_data *data, int y, int x);
int		direct_moves(int keycode, t_data *data);
void	def_img(t_data *data);
void	background(t_data *data);
int		map_size(t_data *data);
int		read_map(int x, int y, t_data *data);
int		map_wall(int y_size, t_data *data);
int		pe_check(int y_size, int c, t_data *data, int count);
int		chr_check(t_data *data, int y_size);
void	ple_loc(int y_size, t_data *data);
void	up_layer(t_data *data);
void	gen_img(t_data *data, int x, int y);
int		exit_game(t_data *data);
char	*ft_strtrim(char *s1, char *set);
void	step_count(int ret);
int		ft_strlcpy(char *dst, char *src, int dstsize);
void	exit_check(t_data *data, int y, int x);
int		valid_path(t_data *data, int y, int x);
void	checkc(t_data *data, int y, int x);
void	trans_map(t_data *data, int i, int y);
void	name_check(t_data *data, char *str);

#endif
