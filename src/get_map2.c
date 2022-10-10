/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:21:40 by steh              #+#    #+#             */
/*   Updated: 2022/10/10 18:58:00 by steh             ###   ########.fr       */
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
	// printf("width: %d\n", map->width);
	// printf("height: %d\n", map->height);
}

void	get_file(int fd, t_game *game)
{
	char	*line;
	char	**strs;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map(line))
			get_map(fd, line, &game->map);
		if (!is_map(line))
		{
			strs = ft_split(line, '\n');
			get_data(strs, &game->scene);
			free_strs(strs);
			free(strs);
		}		
		free(line);
		line = get_next_line(fd);
	}
	// printf("no: %s\n", game->scene.no_tex.path);
	// printf("so: %s\n", game->scene.so_tex.path);
	// printf("we: %s\n", game->scene.we_tex.path);
	// printf("ea: %s\n", game->scene.ea_tex.path);
	// printf("fr: %i\n", game->scene.floor_color.r);
	// printf("fg: %i\n", game->scene.floor_color.g);
	// printf("fb: %i\n", game->scene.floor_color.b);
	// printf("cr: %i\n", game->scene.ceiling_color.r);
	// printf("cg: %i\n", game->scene.ceiling_color.g);
	// printf("cb: %i\n", game->scene.ceiling_color.b);
	free(line);
}
