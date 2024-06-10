#ifndef UTILS_H
# define UTILS_H

#define	BUFFER_SIZE 128

# include "../extra_libs/42_project_libs/src/libft/libft.h"
# include "../extra_libs/42_project_libs/src/get_next_line/get_next_line.h"
# include "../extra_libs/42_project_libs/src/ft_printf/ft_printf.h"
# include "../extra_libs/MLX42/include/MLX42/MLX42.h"
# include "./so_long.h"

void    err_exit(const char *message);
void	find_item_pos(char **map, char item, double *y_pos, double *x_pos);
int     count(char *src, char value);

#endif