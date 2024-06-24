/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:46:10 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/23 19:28:11 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	game_loop(t_data *data)
{
	while (1)
	{
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
		mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
			&game_destroy, data);
		mlx_loop_hook(data->mlx_ptr, &refresh, data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_struct_pointers(&data);
	create_map(&data, argc, argv);
	free_game(&data);
	return (0);
}