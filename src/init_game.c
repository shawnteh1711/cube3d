/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:28:25 by steh              #+#    #+#             */
/*   Updated: 2022/12/16 16:11:50 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	init_game(t_game *game)
{
	game->mlx.ptr = mlx_init();
	game->map.px = 64;
	game->mlx.win_w = game->map.width * game->map.px;
	game->mlx.win_h = game->map.height * game->map.px;
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->mlx.win_w,
			game->mlx.win_h, "cub3d");
	game->texture.width = 165;
	game->texture.height = 256;
	game->map.door_count = 0;
	mlx_mouse_move(game->mlx.win, game->mlx.win_w / 2, game->mlx.win_h / 2);
	game->prev_mouse_x = game->mlx.win_w / 2;
	mlx_mouse_hide();
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
