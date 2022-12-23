/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:57 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:15:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief start from the corner of the screen 
 * width of the whole screen height of half of the screen
 * no border
 * draw rect
 * 
 * @param game 
 */
void	draw_ceilling(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = game->mlx.win_w;
	rect.height = game->mlx.win_h / 2;
	rect.border_width = 0;
	rect.fill_color = game->scene.ceiling_color.argb;
	draw_rect(&rect, game->mlx.img.data, game->mlx.win_w);
}
