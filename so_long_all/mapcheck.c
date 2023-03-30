/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:33:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/30 12:41:50 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

int	map_size(t_data *data)
{
	int		fd;
	int		x;
	int		x1;
	int		y;
	char	*str;

	fd = open("map.ber", O_RDWR, 0777);
	str = get_next_line(fd);
	y = 0;
	x1 = ft_strlen(str);
	while (str)
	{
		y++;
		x = ft_strlen(str);
		if (x != x1)
			return (-1);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	if (x1 == 0 || y == 0)
		return (-1);
	return (read_map(x, y, data));
}

int	read_map(int x, int y, t_data *data)
{
	int		a;
	int		i;

	data -> y_max = y;
	data -> x_max = x - 1;
	i = 0;
	a = 0;
	data -> map = malloc(sizeof(char *) * y);
	data -> temp = malloc(sizeof(char *) * y);
	while (a < y)
	{
		data -> map[a] = malloc(sizeof(char) * (x + 1));
		data -> temp[a++] = malloc(sizeof(char) * (x + 1));
	}
	trans_map(data, i, y);
	i = -1;
	while (++i < data -> y_max)
		ft_strlcpy(data -> temp[i], data -> map[i], data -> x_max);
	return (map_wall(y, data));
}

int	map_wall(int y_size, t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	if (chr_check (data, y_size) == -1)
		return (-1);
	while (data -> map[0][++x] != '\n')
	{
		if (data -> map[0][x] != '1' || data -> map[y_size -1][x] != '1')
			return (-1);
	}
	while (++y < y_size)
	{
		if (data -> map[y][0] != '1' || data -> map[y][x - 1] != '1')
			return (-1);
	}
	if (pe_check(y_size, 'P', data, 0) || pe_check(y_size, 'E', data, 0) \
		|| pe_check(y_size, 'C', data, 0))
		return (-1);
	ple_loc(y_size, data);
	if (valid_path(data, data->p_loc[0], data->p_loc[1]) == 0)
		return (-1);
	return (0);
}

int	pe_check(int y_size, int c, t_data *data, int count)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++y < y_size)
	{
		x = 0;
		while (data -> map[y][++x])
		{
			if (data -> map[y][x] == c)
				count++;
		}
	}
	if ((c == 'E' || c == 'P') && count != 1)
		return (-1);
	else if (c == 'C')
		data -> collect = count;
	data->count = 0;
	return (0);
}
