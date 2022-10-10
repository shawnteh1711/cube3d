/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:09:26 by steh              #+#    #+#             */
/*   Updated: 2022/10/10 19:16:40 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

void	ck_map(t_game *game)
{
	ck_texture(game->scene.no_tex.path, "NO");
	ck_texture(game->scene.so_tex.path, "SO");
	ck_texture(game->scene.we_tex.path, "WE");
	ck_texture(game->scene.ea_tex.path, "EA");
	ck_color(&game->scene.floor_color, "floor color");
	ck_color(&game->scene.ceiling_color, "ceiling color");
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
	// printf("fr: %i\n", color->r);
	// printf("fg: %i\n", color->g);
	// printf("fb: %i\n", color->b);
	if (color->r == -1 || color->g == -1 || color->b == -1)
	{
		printf("%s missing.\n", color_name);
		exit(EXIT_SUCCESS);

	}
	else if (color->r < 0 || color->g < 0 || color->b < 0 ||
		color->r > 255 || color->g > 255 || color->b > 255)
	{
		printf("%s out of range.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	color->argb = create_argb(0, color->r, color->g, color->b);
	// printf("argb: %d\n", color->argb);
}