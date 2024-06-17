/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:57:21 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/17 15:45:38 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	end_game(t_game *game, int exit_code)
{
	free(game->map.map_1d);
	free_2d_array((void **) game->map.map_2d);
	free(game->backup_map.map_1d);
	free_2d_array((void **) game->backup_map.map_2d);

	if (game->mlx)
		mlx_terminate(game->mlx);
	free_2d_array((void **) game->entities.space.sprites); //none
	free_2d_array((void **) game->entities.wall.sprites);
	free_2d_array((void **) game->entities.player.sprites);
	free_2d_array((void **) game->entities.exit.sprites);
	free_2d_array((void **) game->entities.item.sprites);
	free_2d_array((void **) game->entities.enemy.sprites);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
    t_game game;

    if (argc != 2)
        err_exit(FILE_MSG);
    init_struct(&game, argv[1]);
    display_game(&game); //none
    if (mlx_loop_hook(game.mlx, my_loop_hook, (void *) &game) == false) //none
	{
		end_game(&game, EXIT_FAILURE); // none
	}
    mlx_loop(game.mlx);
    end_game(&game, EXIT_FAILURE);
}
