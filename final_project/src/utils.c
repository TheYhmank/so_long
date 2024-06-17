/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:39:18 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/17 15:21:44 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void err_exit(const char *err_mess)
{
    if (err_mess)
        ft_printf(err_mess, 1);
    exit(EXIT_FAILURE);
}

void	find_item_pos(char **map, char item, double *y_pos, double *x_pos)
{
	size_t	y;
	size_t	x;

	if (!map || !*map)
		return ;
	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
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