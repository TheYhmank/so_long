/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:19:27 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/20 17:38:58 by ayermeko         ###   ########.fr       */
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

# include "../extra_libs/minilibx-linux/mlx_int.h"
# include "../extra_libs/42_project_libs/src/ft_printf/ft_printf.h"
# include "../extra_libs/42_project_libs/src/get_next_line/get_next_line.h"
# include "../extra_libs/42_project_libs/src/libft/libft.h"

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

typedef struct s_enemy
{
    int num;
    int count;
    int *x;
    int *y;
    int idle_time;
    char *facing;
} t_enemy;


typedef struct s_player
{
    int x;
    int y;
    int score;
    int moves;
    int win;
    char facing;
} t_player;

typedef struct s_texture
{
    //none
} t_texture;


typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
    t_player *player;
    t_enemy *monster;
    t_texture *texture;
    t_map		*map;
} t_game;


#endif