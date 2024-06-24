/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:53:33 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/24 16:22:53 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_up(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'X')
		data->map->map[data->player->y][data->player->x] = 'E';
	else
		data->map->map[data->player->y][data->player->x] = '0';
	check_up(data);
	if (data->map->map[data->player->y][data->player->x] == 'E')
		data->map->map[data->player->y][data->player->x] = 'X';
	else
		data->map->map[data->player->y][data->player->x] = 'P';
}

void	move_down(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'X')
		data->map->map[data->player->y][data->player->x] = 'E';
	else
		data->map->map[data->player->y][data->player->x] = '0';
	check_down(data);
	if (data->map->map[data->player->y][data->player->x] == 'E')
		data->map->map[data->player->y][data->player->x] = 'X';
	else
		data->map->map[data->player->y][data->player->x] = 'P';
}

void	move_left(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'X')
		data->map->map[data->player->y][data->player->x] = 'E';
	else
		data->map->map[data->player->y][data->player->x] = '0';
	check_left(data);
	if (data->map->map[data->player->y][data->player->x] == 'E')
		data->map->map[data->player->y][data->player->x] = 'X';
	else
		data->map->map[data->player->y][data->player->x] = 'P';
}

void	move_right(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'X')
		data->map->map[data->player->y][data->player->x] = 'E';
	else
		data->map->map[data->player->y][data->player->x] = '0';
	check_right(data);
	if (data->map->map[data->player->y][data->player->x] == 'E')
		data->map->map[data->player->y][data->player->x] = 'X';
	else
		data->map->map[data->player->y][data->player->x] = 'P';
}
