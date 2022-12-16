/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:09:26 by steh              #+#    #+#             */
/*   Updated: 2022/12/15 14:22:10 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

int	map_unknown_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (!ft_strchr("01DNSEW ", map->grid[i][j]))
				return (1);
		}
	}
	return (0);
}

void	ck_maps(t_map *map)
{
	if (map->grid == 0)
	{
		printf("Error\nThe map is missing.\n");
		exit(EXIT_SUCCESS);
	}
	if (map_unknown_char(map))
	{
		printf("Error\nUnknown character in map.\n");
		exit(EXIT_SUCCESS);
	}
	if (!check_map_enclosed(map, map->grid))
	{
		printf("map not enclosed\n");
		exit(EXIT_SUCCESS);
	}
}

void	ck_info(t_game *game)
{
	ck_texture(game->scene.no_tex.path, "NO");
	ck_texture(game->scene.so_tex.path, "SO");
	ck_texture(game->scene.we_tex.path, "WE");
	ck_texture(game->scene.ea_tex.path, "EA");
	ck_color(&game->scene.floor_color, "floor color");
	ck_color(&game->scene.ceiling_color, "ceiling color");
	ck_maps(&game->map);
}

void	ck_texture(char *texture, char *desc)
{
	if (texture == 0)
	{
		printf("%s is missing\n", desc);
		exit(EXIT_SUCCESS);
	}
	if (check_file_exits(texture) == -1
		|| check_file_extension(texture, ".xpm") == -1)
	{
		printf("texture error for %s\n", texture);
		exit(EXIT_SUCCESS);
	}
}

void	ck_color(t_color *color, char *color_name)
{
	if (color->r == -1 || color->g == -1 || color->b == -1)
	{
		printf("%s missing.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	else if (color->r < 0 || color->g < 0 || color->b < 0
		|| color->r > 255 || color->g > 255 || color->b > 255)
	{
		printf("%s out of range.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	color->argb = create_argb(0, color->r, color->g, color->b);
}
