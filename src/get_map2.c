/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:21:40 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 15:54:33 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	extract_dimension(t_map *map)
{
	int		width;
	int		i;

	map->height = 0;
	map->width = 0;
	i = 0;
	width = 0;
	while (map->grid[i] != NULL)
	{
		width = ft_strlen_cube3d(map->grid[i]);
		if (width >= map->width)
			map->width = width;
		map->height++;
		i++;
	}
}

void	get_file(int fd, t_game *game)
{
	char	*line;
	char	**strs;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_map(line))
		{
			strs = ft_split(line, '\n');
			get_data(strs, &game->scene);
			free_strs(strs);
			free(strs);
			free(line);
		}
		else
			get_map(fd, line, &game->map);
		line = get_next_line(fd);
	}
	free(line);
}
