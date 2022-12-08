/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:07:18 by steh              #+#    #+#             */
/*   Updated: 2022/12/08 21:22:13 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/struct.h"
# include "../inc/cube3d.h"

// void	better_angle(double *angle)
// {
// 	if (*angle < 0.0)
// 		*angle += 360.0;
// 	else if (*angle >= 360.0)
// 		*angle -= 360.0;
// }

// void	handle_mouse(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	diff;

// 	x = 0;
// 	y = 0;
// 	mlx_mouse_get_pos(game->mlx.win, &x, &y);
// 	diff = game->prev_mouse_x - x;
// 	printf("diff: %d\n", diff);
// 	printf("b rotation: %f \n", game->player.rotate_angle);
// 	game->player.rotate_angle += (diff / 5);
// 	better_angle(&(game->player.rotate_angle));
// 	printf("a rotation: %f \n", game->player.rotate_angle);
// 	printf("b x: %f\n", game->player.x);
// 	printf("b y: %f\n", game->player.y);
// 	game->player.x += cos(game->player.rotate_angle) * game->player.speed;
// 	game->player.y += sin(game->player.rotate_angle) * game->player.speed;
// 	printf("a x: %f\n", game->player.x);
// 	printf("a y: %f\n", game->player.y);
// 	// game->player.turn_direction = 1;
// 	mlx_mouse_move(game->mlx.win, game->prev_mouse_x , game->mlx.win_h / 2);
// 	// game->player.
// }

void	init_events(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx.ptr);
	mlx_hook(game->mlx.win, KEY_PRESS, M_KEY_PRESS, key_pressed, game);
	mlx_hook(game->mlx.win, KEY_RELEASE, M_KEY_RELEASE, key_released, game);
	mlx_hook(game->mlx.win, DESTROY_NOTIFY, M_DESTROY_NOTIFY, close_window_cross, game);
	// handle_mouse(game);
}

int		key_pressed(int keycode, t_game *game)
{
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
	else if (keycode == K_ESC)
	{
		// free_game(game);
		// system("leaks program");
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		key_released(int keycode, t_game *game)
{
	(void)game;
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		game->player.walk_direction = 0;
	else if (keycode == K_LEFT_ARROW || keycode == K_RIGHT_ARROW)
		game->player.turn_direction = 0;
	return (1);
}

int		close_window_cross(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	exit(EXIT_SUCCESS);
	return (1);
}