/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:01:34 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/10 16:35:34 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void init_pointers(t_game *game, int value)
{
    game->mlx = NULL;
    ft_memset(&game->map, value, sizeof(t_map));
    ft_memset(&game->backup_map, value, sizeof(t_map));
    ft_memset(&game->entities.enemy, value, sizeof(t_entity));
    ft_memset(&game->entities.player, value, sizeof(t_entity));
    ft_memset(&game->entities.exit, value, sizeof(t_entity));
    ft_memset(&game->entities.wall, value, sizeof(t_entity));
    ft_memset(&game->entities.space, value, sizeof(t_entity));
}

void init_struct(t_game *game, char *map_path)
{
    t_img_list imgs;
    
    init_pointers(game, 0);
    init_map(&game->map, map_path);
    if (copy_t_map(&game->backup_map, &game->map) == -1) //none
        end_game(game, EXIT_FAILURE);
}