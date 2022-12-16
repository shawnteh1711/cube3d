/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:11:50 by steh              #+#    #+#             */
/*   Updated: 2022/12/13 20:05:17 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	init_others(t_game *game)
{	
	game->scene.mini_map_tile_size = game->mlx.win_w / MINIMAP_RATIO;
	set_rays(game);
	load_texture(game->mlx.ptr, &game->scene.no_tex);
	load_texture(game->mlx.ptr, &game->scene.so_tex);
	load_texture(game->mlx.ptr, &game->scene.we_tex);
	load_texture(game->mlx.ptr, &game->scene.ea_tex);
	load_texture(game->mlx.ptr, &game->scene.ea_tex);
	game->door.tex.path = "/Users/steh/Documents/steh/own_piscine_repo/cube3d/img/wall.xpm";
	load_texture(game->mlx.ptr, &game->door.tex);
}

void	set_rays(t_game *game)
{
	game->rays.arr = malloc(game->mlx.win_w * sizeof(t_ray));
	if (!game->rays.arr)
		exit(EXIT_SUCCESS);
	game->rays.view_angle = deg_to_rad(VIEW_ANGLE);
	game->rays.dist_proj_plane = (game->mlx.win_w / 2)
		/ tan(game->rays.view_angle / 2);
}

void	load_texture(void *mlx, t_texture *texture)
{
	texture->img.ptr = mlx_xpm_file_to_image(mlx, texture->path,
			&texture->width, &texture->height);
	texture->img.data = (int *)mlx_get_data_addr(texture->img.ptr,
			&texture->img.bpp,
			&texture->img.size,
			&texture->img.endian);
}
