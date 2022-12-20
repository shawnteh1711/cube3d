/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:05:50 by steh              #+#    #+#             */
/*   Updated: 2022/12/20 19:48:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	mouse_event(t_game *game, int keycode)
{
	if (keycode == K_M)
	{
		if (game->mouse_s == 1)
		{
			game->mouse_s = 0;
			mlx_mouse_hide();
		}
		else if (game->mouse_s == 0)
		{
			game->mouse_s = 1;
			mlx_mouse_show();
		}
	}
}

void	handle_mouse(t_game *game)
{
	int	x;
	int	y;
	int	diff;

	mlx_mouse_get_pos(game->mlx.win, &x, &y);
	diff = x - game->prev_mouse_x;
	if (diff > 30)
		game->player.turn_direction += 1;
	else if (diff < -30)
		game->player.turn_direction -= 1;
	else
		game->player.turn_direction = 0;
	mlx_mouse_move(game->mlx.win, game->mlx.win_w / 2, game->mlx.win_h / 2);
	game->prev_mouse_x = game->mlx.win_w / 2;
}

void	update_mouse(t_game *game)
{
	if (game->mouse_s == 0)
	{
		mlx_mouse_hide();
		handle_mouse(game);
	}
	else if (game->mouse_s == 1)
		mlx_mouse_show();
}
