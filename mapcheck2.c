/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:49:44 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/22 19:32:32 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

int	chr_check(t_data *data, int y_size)
{
	int		x;
	int		y;
	char	*a;

	x = -1;
	y = -1;
	while (++y < y_size)
	{
		a = ft_strtrim(data -> map, "CP01E");
		if (!(a[0] == '\n' && a[1] == '\0'))
			return(-1);
	}
	free(a);
}

void	col_loc(int count, int y_size, t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	data -> loc -> c_xloc = malloc(sizeof(int) * count);
	data -> loc -> c_yloc = malloc(sizeof(int) * count);
	while (++y < y_size)
	{
		while (data -> map[y][++x] && count)
		{
			if (data -> map[y][x] == 'C' && count--)
			{
				data -> loc -> c_xloc[i] = x;
				data -> loc -> c_yloc[i++] = y;
			}
		}
	}
	pl_loc(y_size, data);
}

void	pl_loc(int y_size, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++y < y_size)
	{
		while (data -> map[y][++x])
		{
			if (data -> map[y][x] == 'P')
			{
				data -> loc -> p_loc[0] = y;
				data -> loc -> p_loc[1] = x;
				return;
			}
		}
	}
}
