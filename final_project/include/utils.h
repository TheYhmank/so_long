/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:41:11 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/17 15:46:45 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../extra_libs/MLX42/include/MLX42/MLX42.h"
# include "../extra_libs/42_project_libs/src/libft/libft.h"

void err_exit(const char *err_mess);
void	find_item_pos(char **map, char item, double *y_pos, double *x_pos);

#endif