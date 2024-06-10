/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:04:21 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/10 20:07:52 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int copy_t_map(t_map *map_dest, t_map *map_src)
{
    if (!map_dest | !map_src)
        return (-1);
    *map_dest = *map_src;
    map_dest->map_1d = ft_strdup(map_src->map_1d);
	if (!map_dest->map_1d)
		return (-1);
	map_dest->map_2d = dup_map(map_src->map_2d, map_src->height);
	if (!map_dest->map_2d)
		return (-1);
	return (0);
}