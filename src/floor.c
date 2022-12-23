/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:25:06 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:22:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief start from x = 0
 * start from half of the screen 
 * get the colour
 * draw the floor 
 * 
 * @param game 
 */
void	draw_floor(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = game->mlx.win_h / 2;
	rect.width = game->mlx.win_w;
	rect.height = game->mlx.win_h / 2;
	rect.border_width = 0;
	rect.fill_color = game->scene.floor_color.argb;
	draw_rect(&rect, game->mlx.img.data, game->mlx.win_w);
}
