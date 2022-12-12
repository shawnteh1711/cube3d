/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:05:50 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 17:17:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	handle_mouse(t_game *game)
{
	int	x;
	int	y;
	int	diff;

	mlx_mouse_get_pos(game->mlx.win, &x, &y);
	diff = x - game->prev_mouse_x;
	if (diff > 0)
		game->player.turn_direction += 1;
	else if (diff < 0)
		game->player.turn_direction -= 1;
	else
		game->player.turn_direction = 0;
	mlx_mouse_move(game->mlx.win, game->mlx.win_w / 2, game->mlx.win_h / 2);
	game->prev_mouse_x = game->mlx.win_w / 2;
}
