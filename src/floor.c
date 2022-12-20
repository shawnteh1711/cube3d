/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:25:06 by steh              #+#    #+#             */
/*   Updated: 2022/12/19 20:25:16 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	draw_floor(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = WIN_H / 2;
	rect.width = WIN_W;
	rect.height = WIN_H / 2;
	rect.border_width = 0;
	rect.fill_color = game->scene.floor_color.argb;
	draw_rect(&rect, game->mlx.img.data, game->mlx.win_w);
}
