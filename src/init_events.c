/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:07:18 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:24:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	init_events(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx.ptr);
	mlx_hook(game->mlx.win, KEY_PRESS, M_KEY_PRESS, key_pressed, game);
	mlx_hook(game->mlx.win, KEY_RELEASE, M_KEY_RELEASE, key_released, game);
	mlx_hook(game->mlx.win, DESTROY_NOTIFY, M_DESTROY_NOTIFY,
		close_window_cross, game);
}

int	key_pressed(int keycode, t_game *game)
{
	mouse_event(game, keycode);
	if (keycode == K_W)
		game->player.walk_direction = 'w';
	else if (keycode == K_A)
		game->player.walk_direction = 'a';
	else if (keycode == K_S)
		game->player.walk_direction = 's';
	else if (keycode == K_D)
		game->player.walk_direction = 'd';
	else if (keycode == K_LEFT_ARROW)
		game->player.turn_direction = -1;
	else if (keycode == K_RIGHT_ARROW)
		game->player.turn_direction = 1;
	else if (keycode == K_SP)
		change_door(game);
	else if (keycode == K_ESC)
	{
		free_game(game);
		//system("leaks cub3D");
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	key_released(int keycode, t_game *game)
{
	(void)game;
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		game->player.walk_direction = 0;
	else if (keycode == K_LEFT_ARROW || keycode == K_RIGHT_ARROW)
		game->player.turn_direction = 0;
	return (1);
}

int	close_window_cross(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	exit(EXIT_SUCCESS);
	return (1);
}
