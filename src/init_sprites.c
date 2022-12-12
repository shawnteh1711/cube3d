/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:56:21 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 17:14:39 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	init_sprite(t_game *game)
{
	game->anime.images = (t_img *)malloc(sizeof(t_img) * 20);
	put_anime_image(game, 0, SPRITE0);
	put_anime_image(game, 1, SPRITE1);
	put_anime_image(game, 2, SPRITE2);
	put_anime_image(game, 3, SPRITE3);
	put_anime_image(game, 4, SPRITE4);
	put_anime_image(game, 5, SPRITE5);
}

void	put_anime_image(t_game *game, int i, char *path)
{
	(game->anime.images)[i].ptr = mlx_xpm_file_to_image(game->mlx.ptr, path,
			&game->texture.width, &game->texture.height);
	(game->anime.images)[i].data = (int *)mlx_get_data_addr((
				game->anime.images)[i].ptr,
			&(game->anime.images)[i].bpp,
			&(game->anime.images)[i].size,
			&(game->anime.images)[i].endian);
}
