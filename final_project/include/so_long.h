/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:19:27 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/23 21:46:20 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Tile size (square)
# define SIZE	32

// Frame rate
# define FRAME_RATE	60

// Key input
# define KEY_UP	65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100
# define KEY_ESC	65307

# include "../extra_libs/minilibx-linux/mlx.h"
# include "../extra_libs/minilibx-linux/mlx_int.h"
# include "../extra_libs/42_project_libs/includes/libft.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_map
{
	int		e_count;
	int		p_count;
	int		c_count;
	int		m_count;
	int		e_found;
	int		c_found;
	int		row;
	int		col;
	int		start_row;
	int		start_col;
	int		current_line;
	int		current_col;
	int		len;
	int		fdmap;
	int		error_flag;
	int		fd;
	int		width;
	int		height;
	char	*line;
	char	*prev_line;
	char	**map;
	char	**map_buffer;
	char	check;
}	t_map;

typedef struct s_monster
{
	int		num;
	int		count;
	int		*x;
	int		*y;
	int		idle_time;
	char	init_facing;
	char	*facing;
}	t_monster;

typedef struct s_player
{
	int		x;
	int		y;
	int		score;
	int		moves;
	int		win;
	char	facing;
}	t_player;

typedef struct s_texture
{
	void	*player_l[4];
	void	*player_r[4];
	void	*monster_l[4];
	void	*monster_r[4];
	void	*collect[4];
	void	*exit[2];
	void	*wall;
	void	*floor;
	int		*px_size;
	int		*px_height;
	int		*px_width;
	int		keyframe;
	int		frame;
}	t_texture;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*player;
	t_monster	*monster;
	t_texture	*texture;
	t_map		*map;
}	t_data;

// event.c
int		game_destroy(t_data *data);
int		on_keypress(int keysym, t_data *data);
int		refresh(t_data *data);
void	key_event(int keysym, t_data *data);

// logic.c
void	check_up(t_data *data);
void	check_down(t_data *data);
void	check_left(t_data *data);
void	check_right(t_data *data);

// main.c
int		game_loop(t_data *data);

// map.c
void	draw_map(t_data *data, t_map *c, t_texture *t);
void	create_map(t_data *data, int argc, char **argv);

// monster_logic.c
void	monster_logic(t_data *data);

// move.c
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

// init.c
void	init_vars(t_data *init);
void	init_struct_pointers(t_data *data);
int		init_player_coords(t_map *c, t_player *p, int row, int col);
void	init_monster_coords(t_map *c, t_monster *mon);

// mem.c
void	free_game(t_data *data);
void	mem_monster(t_data *data);
void	mem_alloc(t_map *c);

// open_ber.c
int		open_ber(t_map *c, char *map_name, int ac, char **av);

// render.c
void	render_moves(t_data *d, t_map *c);
void	render_xpm(t_data *data, t_texture *t);
void	render_xpm(t_data *data, t_texture *t);
void	render_image(t_data *d, void *img_ptr, t_map *c);

// validate_path.c
int		boundary_check(t_map *c);
void	invalid_format(t_map *c);
bool	validate_path(t_map *c, t_player *p, int fd);
bool	is_valid_path(t_map *c, int row, int col);
bool	pathing_map(t_map *c, int row, int col);

#endif