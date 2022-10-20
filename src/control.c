/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:32:52 by steh              #+#    #+#             */
/*   Updated: 2022/10/18 12:31:06 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"
#include "../inc/keycode.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		ft_exit("Esc game", &game->map);
	// if (keycode == W_KEY)
	// 	game->player.walk_direction = 'w';
	// if (keycode == S_KEY)
	// 	game->player.walk_direction = 's';
	// if (keycode == A_KEY)
	// 	game->player.walk_direction = 'a';
	// if (keycode == D_KEY)
	// 	game->player.walk_direction = 'd';

	if (keycode == W_KEY)
		game->player.y -= game->map.px;
	if (keycode == S_KEY)
		game->player.y += game->map.px;
	if (keycode == A_KEY)
		game->player.x -= game->map.px;
	if (keycode == D_KEY)
		game->player.x += game->map.px;
	printf("y: %f\n", game->player.y);
	printf("x: %f\n", game->player.x);
	return (0);
}