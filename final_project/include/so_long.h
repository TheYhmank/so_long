/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:56:38 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/17 15:45:24 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "../extra_libs/42_project_libs/src/ft_printf/ft_printf.h"
# include "../extra_libs/42_project_libs/src/libft/libft.h"
# include "../extra_libs/42_project_libs/src/get_next_line/get_next_line.h"
# include "../extra_libs/MLX42/include/MLX42/MLX42.h"
# include "./utils.h"

# define FILE_MSG "Error\nIncorrect number of parameters, only 2 are accepted.\n"
# define FILE_EXT_MSG "Error\nFile has invalid file extension\n"
# define EMPTY_MSG "Error\nMap is empty or opening file failed\n"
# define RECT_MSG "Error\nMap is not rectangle.\n"
# define WRONG_MSG "Error\nMap have the wrongs components\n"
# define WALL_MSG "Error\nMap don't have close walls\n"
# define MIN_TILES_MSG "Error\nYou don't have the correct components\n"
# define PATH_MSG "Error\nThere is not a valid path\n"

enum e_entity
{
	SPACE = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	ITEM = 'C',
	ENEMY = 'M'
};

enum e_direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

typedef struct s_vector
{
	double	x;
	double	y;
} t_vector;

typedef struct s_map
{
	char		*map_1d;
	char		**map_2d;
	size_t		height;
	size_t		width;
	t_vector	player_pos;
	t_vector	exit_pos;
	size_t		num_items;
	size_t		num_enemies;
	int			steps;
	mlx_image_t	*steps_img;
} t_map;

typedef struct s_backup
{
	char *map_1d;
	char **map_2d;
} t_backup;

typedef struct s_img_list
{
	mlx_image_t *space;
	mlx_image_t *wall;
	mlx_image_t *player;
	mlx_image_t *exit;
	mlx_image_t *items;
	mlx_image_t *enemies;
} t_img_list;

typedef struct s_entity
{
	enum e_entity	type;
	mlx_image_t		***sprites;
	size_t			num_variations;
	size_t			current_variation;
	size_t			num_frames;
	size_t			current_frame;
	int				fps;
	double			delta_time;
} t_entity;

typedef struct s_entity_list
{
	t_entity space;
	t_entity wall;
	t_entity player;
	t_entity exit;
	t_entity item;
	t_entity enemy;
} t_entity_list;

typedef struct s_menu
{
	mlx_image_t *background;
	mlx_image_t *message;
} t_menu;

typedef struct s_menu_list
{
	t_menu	failure;
	t_menu	success;

} t_menu_list;

typedef struct	s_game
{
	mlx_t			*mlx;
	t_map 			map;
	t_map 			backup_map;
	t_entity_list	entities;
	t_menu_list		menus;
} t_game;


void init_struct(t_game *game, char* map_path);
void init_map(t_map *map, const char *map_path);
void	my_loop_hook(void *param);

#endif