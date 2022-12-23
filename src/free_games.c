/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_games.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:02:39 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:17:49 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	free_game(t_game *game)
{
	free_scene(&game->scene, &game->map);
	free(game->rays.arr);
}

void	free_scene(t_scene *scene, t_map *map)
{
	free(scene->no_tex.path);
	free(scene->so_tex.path);
	free(scene->we_tex.path);
	free(scene->ea_tex.path);
	free(scene->sprite_tex.path);
	if (map->door_count >= 1)
		free(scene->do_tex.path);
	free_map(map);
	free(scene->sprites);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		free(map->grid[i]);
	}
	free(map->grid);
}
