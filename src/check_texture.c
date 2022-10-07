/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:09:26 by steh              #+#    #+#             */
/*   Updated: 2022/10/07 22:31:35 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

void	ck_texture(t_game *game)
{
	char *texture[] = {
		game->scene.no_tex.path,
		game->scene.so_tex.path,
		game->scene.we_tex.path,
		game->scene.ea_tex.path,
	};

	int size = sizeof(texture) / sizeof(texture[0]);
	// for (int i = 0; i < size; i++)
	// {
	// 	printf("%s\n", texture[i]);
	// }
	
	int	i;

	i = 0;
	while (i < size)
	{
		if (check_file_exits(texture[i]) == -1
			|| check_file_extension(texture[i], ".xpm") == -1)
		printf("texture error for %d, %s\n",i, texture[i]);
		i++;
	}
	
	// if (!check_file_exits(game->scene.no_tex.path) 
	// || !check_file_extension(game->scene.no_tex.path, ".xpm"))
	// 	printf("texture error\n");
	// int	i = check_file_exits(game.scene.no_tex.path);
	// int	j = check_file_extension(game.scene.no_tex.path, ".xpm");
	// printf("no: %s\n", game.scene.no_tex.path);
	// printf("i: %d\n", i);
	// printf("j: %d\n", j);
	// printf("so: %s\n", game.scene.so_tex.path);
	// printf("we: %s\n", game.scene.we_tex.path);
	// printf("ea: %s\n", game.scene.ea_tex.path);
	// printf("fr: %i\n", game.scene.floor_color.r);
	// printf("fg: %i\n", game.scene.floor_color.g);
	// printf("fb: %i\n", game.scene.floor_color.b);
	// printf("cr: %i\n", game.scene.ceiling_color.r);
	// printf("cg: %i\n", game.scene.ceiling_color.g);
	// printf("cb: %i\n", game.scene.ceiling_color.b);
	// printf("\n\n");
}