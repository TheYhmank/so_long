/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:12:20 by ayermeko          #+#    #+#             */
/*   Updated: 2024/06/10 15:12:35 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char *read_map(int fd)
{
    char    *content;
    char    *buffer;
    char    *temp;
    int     bytes_read;

    content = NULL;
    buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
    if (!buffer)
        return (NULL);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE - 1)) != 0)
    {
        if (bytes_read < 0)
            return (free(buffer), free(content), NULL);
        temp = ft_strjoin(content, buffer);
        if (!temp)
            return (free(buffer), free(content), NULL);
        free(content);
        content = temp;
        ft_bzero(buffer, ft_strlen(buffer));    
    }
    free(buffer);
    return (content);
}

static bool valid_file_extension(const char* path)
{
    size_t strlen;

    strlen = ft_strlen(path);
    if (strlen < 4 || ft_strncmp(&path[strlen - 4], ".ber", 4) != 0)
        return (0);
    return (1);   
}

static char *get_map(const char *path)
{
    int     fd;
    char    *map;
    
    if (!valid_file_extension(path))
        err_exit(FILE_EXT_MSG);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        err_exit(EMPTY_MSG);
    map = read_file(fd);
    if (!map)
        err_exit(EMPTY_MSG);
    return (map);     
}

static size_t	get_height(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		i++;
	}
	return (i);
}

void init_map(t_map *map, const char *map_path)
{
    map->map_1d = get_map(map_path);
    map->map_2d = ft_split(map->map_1d, '\n');
    if (!map->map_2d)
    {
        free(map->map_1d);
        exit(EXIT_FAILURE);
    }
    map->height = get_height(map->map_2d);
    map->width = ft_strlen(map->map_2d[0]);
    find_item_pos(map->map_2d, EXIT, &map->exit_pos.y_axis, &map->exit_pos.x_axis);
    find_item_pos(map->map_2d, PLAYER, &map->player_pos.y_axis, &map->player_pos.x_axis);
    map->num_items = count(map->map_1d, ITEM);
    map->num_enemies = count(map->map_1d, ENEMY);
}