/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:33:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/20 21:33:24 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "oslo.h"

void	map_size(void)
{
	int		fd;
	int		x;
	int		x1;
	int		y;
	char	*str;

	fd = open("map.txt", O_RDWR, 0777);
	str = get_next_line(fd);
	y = 0;
	x1 = ft_strlen(str);
	while (str)
	{
		y++;
		x = ft_strlen(str);
		if(x != x1)
			//error map valid değil
		str = get_next_line(fd);
	}
	free(str);
	if (x1 == 0 || y == 0)
		//error map valid değil
	read_map(x, y);
}

void	read_map(int x, int y)
{
	char	**map;
	int		a;
	int		fd;
	int		i;

	i = 0;
	a = 0;
	map = malloc(sizeof(char *) * y);
	while(a < y)
		map[a++] = malloc(sizeof(char) * (x + 1));
	fd = open("map.txt", O_RDWR, 0777);
	while(i < y)
		map[i++] = get_next_line(fd);
	map_wall(map, y - 1); // \n a kadar kontroller için y -1
}

void	map_wall(char **map, int y_size)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[0][++x])
	{
		if (map[0][x] != '1' || map[y_size -1][x] != 1)
			//map valid değil
	}
	while (++y < y_size)
	{
		if (map[y][0] != '1' || map[y][x -1] != '1')
		//map valid değil
	}
	pe_check(map, y_size, 'E');
	pe_check(map, y_size, 'P');
	col_check(map, y_size); // collect sizeı geri döndürüyor.
}

void	pe_check(char **map, int y_size, int c)
{
	int	x;
	int	y;
	int	i;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (++y < y_size)
	{
		while (map[y][++x] && count <= 1)
		{
			if (map[y][x] == c)
			{
				if (map[y][x-1] == '1' && map[y][x+1] == '1' && \
					map[y-1][x] == '1' && map[y+1][x] =='1')
					//invalid map
				count++;
			}
		}
	}
	if (count != 1)
	//invalid map
}

int	col_check(char **map, int y_size)
{
	int	x;
	int	y;
	int	i;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (++y < y_size - 1)
	{
		while (map[y][++x] && count <= 1)
		{
			if (map[y][x] != 'C' && map[y][x] == '1' && map[y][x] != '0' && \
			map[y][x] != 'P' && map[y][x] != 'E') // strtrim döndürüp boş gelmezse invalid diyebilirsin
			//invalid map
			if (map[y][x] == 'C')
			{
				if (map[y][x-1] == '1' && map[y][x+1] == '1' && \
					map[y-1][x] == '1' && map[y+1][x] =='1')
					//invalid map
				count++;
			}
		}
	}
	return (count);
}
