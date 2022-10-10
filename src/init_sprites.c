/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:56:21 by steh              #+#    #+#             */
/*   Updated: 2022/10/10 14:06:47 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../inc/struct.h"
# include "../inc/cube3d.h"

void	init_sprites(t_game *game)
{
	get_map_items(&game->scene, &game->map);
}

/*
** Parses the grid and adds a sprite each time it finds one
** @param:	- [t_scene *] scene struct
**			- [t_map *] map struct with grid, height and width
*/

void	get_map_items(t_scene *scene, t_map *map)
{
	int		i;
	int		j;

	scene->total_sprites = 0;
	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == '2')
			{
				add_sprite(scene, j, i);
				scene->total_sprites++;
			}
		}
	}
}

/*
** Sprites are stored in an array of t_sprite
** @param:	- [t_scene *] scene struct
**			- [int] x position of the sprite in the grid
** Line-by-line comments:
** @3-8		If it's the first sprite added, I need to malloc. That way I'm
**			sure I can realloc on the standard case
** @9-16	It's not the first so we realloc to total + 1
** @18-19	The sprites need to be in the center of the grid boxes
*/

void	add_sprite(t_scene *scene, int x, int y)
{
	int	last_sprite_index;

	if (scene->total_sprites == 0)
	{
		scene->sprites = malloc(sizeof(t_sprite));
		if (!scene->sprites)
			exit(EXIT_SUCCESS);
	}
	else
	{
		scene->sprites = ft_realloc(scene->sprites,
				scene->total_sprites * sizeof(t_sprite),
				(scene->total_sprites + 1) * sizeof(t_sprite));
		if (!scene->sprites)
			exit(EXIT_SUCCESS);
	}
	last_sprite_index = scene->total_sprites;
	scene->sprites[last_sprite_index].x = (double)x + 0.5;
	scene->sprites[last_sprite_index].y = (double)y + 0.5;
	scene->sprites[last_sprite_index].tex = &scene->sprite_tex;
}