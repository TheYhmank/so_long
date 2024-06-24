/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:32:23 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/24 16:23:03 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	monster_left(t_data *data, int num)
{
	char	co;

	co = data->map->map[data->monster->y[num]][data->monster->x[num] - 1];
	if (co == '1' || co == 'E' || co == 'C' || co == 'M' || co == 'X')
	{
		data->monster->facing[num] = 'R';
	}
	else if (co == 'P')
	{
		ft_printf("You lost!\n");
		game_destroy(data);
	}
	else
	{
		data->map->map[data->monster->y[num]][data->monster->x[num]] = '0';
		data->monster->x[num]--;
		data->map->map[data->monster->y[num]][data->monster->x[num]] = 'M';
	}
}

static void	monster_right(t_data *data, int num)
{
	char	co;

	co = data->map->map[data->monster->y[num]][data->monster->x[num] + 1];
	if (co == '1' || co == 'E' || co == 'C' || co == 'M' || co == 'X')
	{
		data->monster->facing[num] = 'L';
	}
	else if (co == 'P')
	{
		ft_printf("You lost!\n");
		game_destroy(data);
	}
	else
	{
		data->map->map[data->monster->y[num]][data->monster->x[num]] = '0';
		data->monster->x[num]++;
		data->map->map[data->monster->y[num]][data->monster->x[num]] = 'M';
	}
}

static void	monster_move(t_data *data)
{
	int	num;

	num = 0;
	data->monster->idle_time = (data->monster->idle_time + 1) % 60;
	while (num < data->map->m_count)
	{
		if (data->monster->idle_time == 0)
		{
			if (data->monster->facing[num] == 'L')
			{
				monster_left(data, num);
			}
			else if (data->monster->facing[num] == 'R')
			{
				monster_right(data, num);
			}
		}
		num++;
	}
}

void	monster_logic(t_data *data)
{
	init_monster_coords(data->map, data->monster);
	monster_move(data);
}
