/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:06:07 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/10 16:23:27 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int copy_t_map(t_map *map_dest, t_map *map_src)
{
    if (!map_dest | !map_src)
        return (-1);
    *map_dest = *map_src;  
}