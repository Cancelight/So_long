/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:33:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/24 12:32:29 by bkiziler         ###   ########.fr       */
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
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
	if (x1 == 0 || y == 0)
		return (-1);
	return (read_map(x, y, data));
}

int	read_map(int x, int y, t_data *data)
{
	int		a;
	int		fd;
	int		i;

	data -> y_max = y;
	data -> x_max = x - 1;
	i = 0;
	a = 0;
	data -> map = malloc(sizeof(char *) * y);
	while (a < y)
		data -> map[a++] = malloc(sizeof(char) * (x + 1));
	fd = open("map.ber", O_RDWR, 0777);
	while (i < y)
		data -> map[i++] = get_next_line(fd);
	close(fd);
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
			return(-1);
	}
	while (++y < y_size)
	{
		if (data -> map[y][0] != '1' || data -> map[y][x - 1] != '1')
			return(-1);
	}
	if (pe_check(y_size, 'P', data) == -1 || pe_check(y_size, 'E', data) == -1 \
		|| pe_check(y_size, 'C', data) == -1)
		return (-1);
	ple_loc(y_size, data);
	return (0);
}

int	pe_check(int y_size, int c, t_data *data)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (++y < y_size)
	{
		x = 0;
		while (data -> map[y][++x])
		{
			if (data -> map[y][x] == c)
			{
				if (data -> map[y][x-1] == '1' && data -> map[y][x+1] == '1' && \
					data -> map[y-1][x] == '1' && data -> map[y+1][x] =='1')
					return(-1);
				count++;
			}
		}
	}
	if ((c == 'E' || c == 'P') && count != 1)
		return(-1);
	else if (c == 'C')
		data -> collect = count;
	return(0);
}
