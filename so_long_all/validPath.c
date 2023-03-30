/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validPath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:27 by bkiziler          #+#    #+#             */
/*   Updated: 2023/03/30 13:48:57 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oslo.h"

int	valid_path(t_data *data, int y, int x)
{
	if (data->temp[y][x + 1] && data->temp[y][x + 1] != '1' && \
	data->temp[y][x + 1] != '-')
		checkc(data, y, x + 1);
	if (data->temp[y - 1][x] && data->temp[y - 1][x] != '1' && \
	data->temp[y - 1][x] != '-')
		checkc(data, y - 1, x);
	if (data->temp[y][x - 1] && data->temp[y][x - 1] != '1' && \
	data->temp[y][x - 1] != '-')
		checkc(data, y, x - 1);
	if (data->temp[y + 1][x] && data->temp[y + 1][x] != '1' && \
	data->temp[y + 1][x] != '-')
		checkc(data, y + 1, x);
	return (data->count == data -> collect + 1);
}

void	checkc(t_data *data, int y, int x)
{
	ft_printf("y: %d, x: %d v:%c\n", y, x, data->temp[y][x]);
	if (data->temp[y][x] == 'E' || data->temp[y][x] == 'C')
			data->count++;
	data->temp[y][x] = '-';
	valid_path(data, y, x);
}
