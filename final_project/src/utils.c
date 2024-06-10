/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:45:50 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/10 17:19:06 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void err_exit(const char *message)
{
    if (message)
        ft_printf(message, 1);
    exit(EXIT_FAILURE);
}

char	**dup_map(char **map, size_t size)
{
	size_t 	y;
	char	**dup_map;

	y = 0;
	if (!map || !*map)
		return (NULL);
	dup_map = malloc((size + 1) * sizeof(char *));
	if (!dup_map)
		return (NULL);
	while (map[y])
	{
		dup_map[y] = ft_strdup(map[y]);
		if (!dup_map[y])
		{
			free_2d_array((void **) dup_map);
			return (NULL);
		}
		y++;
	}
	dup_map[size] = NULL;
	return (dup_map);
}

void	find_item_pos(char **map, char item, double *y_pos, double *x_pos)
{
    size_t y;
    size_t x;

    if (!map || !*map)
        return ;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == item)
            {
                *x_pos = x;
                *y_pos = y;
                return ;
            }
            x++;
        }
        y++;
    }
    *x_pos = -1;
	*y_pos = -1; 
}

int	count(char *src, char value)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[i])
	{
		if (src[i] == value)
			count++;
		i++;
	}
	return (count);
}