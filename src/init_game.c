/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:28:25 by steh              #+#    #+#             */
/*   Updated: 2022/12/20 19:47:52 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	init_game(t_game *game)
{
	game->mlx.ptr = mlx_init();
	game->mlx.win_w = 1280;
	game->mlx.win_h = 800;
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->mlx.win_w,
			game->mlx.win_h, "cub3d");
	game->map.door_count = 0;
	game->mouse_s = 0;
	mlx_mouse_move(game->mlx.win, game->mlx.win_w / 2, game->mlx.win_h / 2);
	game->prev_mouse_x = game->mlx.win_w / 2;
	ready_game(game);
	render_game(game);
}

void	ready_game(t_game *game)
{
	init_sprite(game);
	init_player(game);
	init_events(game);
	init_others(game);
}
