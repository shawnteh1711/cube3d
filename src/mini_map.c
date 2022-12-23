/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:32:43 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:34:25 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief get the size of the tile based on the ratio
 * get the height of the mini map
 * if mini map height too big for window, dont print
 * 
 * @param game 
 */
void	draw_mini_map(t_game *game)
{
	int	height_mini_map;

	game->scene.mini_map_tile_size = game->mlx.win_w / MINIMAP_RATIO;
	height_mini_map = game->scene.mini_map_tile_size * game->map.height
		+ MINIMAP_OFFSET * 2;
	if (height_mini_map > game->mlx.win_h)
		return ;
	draw_map(game);
	draw_player(game, game->scene.mini_map_tile_size);
}

/**
 * @brief draw the rays
 * get the radius of the player dot
 * find the position of the player in the x
 * find the position of the player in the y
 * fill the colour to red
 * fill the circle slowly by reducing the radius
 * 
 * @param game 
 * @param tile_size 
 */
void	draw_player(t_game *game, double tile_size)
{
	t_circle	circle;

	draw_rays(game, tile_size);
	game->player.rad = ceil(tile_size / 2);
	circle.x = game->player.x * tile_size + MINIMAP_OFFSET;
	circle.y = game->player.y * tile_size + MINIMAP_OFFSET;
	circle.radius = game->player.rad;
	circle.fill_color = 0x00e63946;
	while (circle.radius--)
		draw_circle(&circle, game->mlx.img.data, game->mlx.win_w);
}

/**
 * @brief find the x and y of the player, starting pos of the line
 * find the ending x and y of the ray
 * fill the colour
 * draw the line
 * 
 * @param game 
 * @param tile_size 
 */
void	draw_rays(t_game *game, double tile_size)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < game->mlx.win_w)
	{
		line.begin_x = game->player.x * tile_size + MINIMAP_OFFSET;
		line.begin_y = game->player.y * tile_size + MINIMAP_OFFSET;
		line.end_x = line.begin_x
			+ cos(game->rays.arr[i].angle)
			* tile_size * game->rays.arr[i].size;
		line.end_y = line.begin_y
			+ sin(game->rays.arr[i].angle)
			* tile_size * game->rays.arr[i].size;
		line.color = 0x00F6B8BD;
		draw_line(&line, game->mlx.img.data, game->mlx.win_w);
	}
}
