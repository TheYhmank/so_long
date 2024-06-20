/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:42:55 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/20 17:57:04 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	init_map(t_game *init)
{
	init->map->e_count = 0;
	init->map->p_count = 0;
	init->map->c_count = 0;
	init->map->m_count = 0;
	init->map->e_found = 0;
	init->map->c_found = 0;
	init->map->current_line = 0;
	init->map->current_col = 0;
	init->map->len = 0;
	init->map->fd = 0;
	init->map->fdmap = 0;
	init->map->row = 0;
	init->map->col = 0;
	init->map->start_row = -1;
	init->map->start_col = -1;
	init->map->error_flag = 0;
	init->map->line = "";
}

void init_vars(t_game *init)
{
    init_map(init);
    init->player->x = 0;
	init->player->y = 0;
	init->player->moves = 0;
	init->player->score = 0;
	init->player->win = 0;
	init->player->facing = 'L';
	init->monster->num = 0;
	init->monster->count = 0;
	init->monster->idle_time = 10;
	init->monster->init_facing = 'R';
}

void init_struct_pointers(t_game *data)
{
    data->map = ft_calloc(1, sizeof(t_map));
    data->player = ft_calloc(1, sizeof(t_player));
    data->monster = ft_calloc(1, sizeof(t_enemy));
    data->texture = ft_calloc(1, sizeof(t_texture));
    return ;
}