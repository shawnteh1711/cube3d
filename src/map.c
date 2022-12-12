/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:25:46 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 17:15:40 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	draw_map(t_game *game)
{
	int		i;
	int		j;
	char	grid_item;
	t_rect	rect;

	i = -1;
	while (game->map.grid[++i])
	{
		j = -1;
		while (game->map.grid[i][++j])
		{
			grid_item = game->map.grid[i][j];
			if (grid_item == ' ')
				continue ;
			rect.x = j * game->scene.mini_map_tile_size + MINIMAP_OFFSET;
			rect.y = i * game->scene.mini_map_tile_size + MINIMAP_OFFSET;
			rect.width = game->scene.mini_map_tile_size;
			rect.height = game->scene.mini_map_tile_size;
			rect.border_color = 0x0014213d;
			rect.border_width = 2;
			rect.fill_color = get_fill_color(&game->scene.floor_color,
					grid_item);
			draw_rect(&rect, game->mlx.img.data, game->mlx.win_w);
		}
	}
}

int	get_fill_color(t_color *floor_color, char grid_item)
{
	int	color;

	if (grid_item == '1')
		color = floor_color->argb;
	else if (grid_item == '2')
		color = 0x00fca311;
	else
		color = 0x00FFFFFF;
	return (color);
}
