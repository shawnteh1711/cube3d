/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:28:25 by steh              #+#    #+#             */
/*   Updated: 2022/10/10 16:04:25 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../inc/struct.h"
# include "../inc/cube3d.h"

void	init_game(t_game *game)
{
	game->mlx.ptr = mlx_init();
	game->map.px = 64;
	game->mlx.win_w = game->map.width * game->map.px;
	game->mlx.win_h = game->map.height * game->map.px;
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->mlx.win_w, game->mlx.win_h, "cub3d");
	game->texture.width = 64;
	game->texture.height = 64;
	printf("1\n");
	init_map(game);
	printf("2\n");
	init_player(game);
	printf("3\n");
	init_sprites(game);
	printf("4\n");
	init_events(game);
	printf("5\n");
}

void	init_player(t_game *game)
{
	game->player.walk_direction = 0;
	game->player.speed = 0.15;
	game->player.turn_direction = 0;
	game->player.rotate_speed = deg_to_rad(4);
	player_start_position(&game->player, game->map.grid);
	
}

double	get_starting_orientation(char orientation)
{
	double	radian;

	radian = 0;
	if (orientation == 'N')
		radian = deg_to_rad(270);
	else if (orientation == 'S')
		radian = deg_to_rad(90);
	else if (orientation == 'E')
		radian = deg_to_rad(360);
	else if (orientation == 'W')
		radian = deg_to_rad(180);
	return (radian);
}


void	player_start_position(t_player *player, char **grid)
{
	int	i;
	int	j;

	i = -1;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (ft_strchr("NSEW", grid[i][j]))
			{
				player->x = j + 0.5;
				printf("player x: %f\n", player->x);
				player->y = i + 0.5;
				printf("player y: %f\n", player->y);
				player->rotate_angle = get_starting_orientation(grid[i][j]);
				printf("player rotation: %f\n", player->rotate_angle);
				grid[i][j] = '0';
			}
		}
		i++;
	}
}

void	set_rays(t_game *game)
{
	game->rays.arr = malloc(game->map.width * sizeof(t_ray));
	if (!game->rays.arr)
		exit(EXIT_SUCCESS);
	game->rays.view_angle = deg_to_rad(VIEW_ANGLE);
	game->rays.dist_proj_plane = (game->map.width / 2)
		/ tan(game->rays.view_angle / 2);
}

void	init_map(t_game *game)
{
	set_rays(game);
	game->scene.no_tex.img.ptr = mlx_xpm_file_to_image(game->mlx.ptr, game->scene.no_tex.path, &game->texture.width, &game->texture.height);
	game->scene.so_tex.img.ptr = mlx_xpm_file_to_image(game->mlx.ptr, game->scene.so_tex.path, &game->texture.width, &game->texture.height);
	game->scene.ea_tex.img.ptr = mlx_xpm_file_to_image(game->mlx.ptr, game->scene.ea_tex.path, &game->texture.width, &game->texture.height);
	game->scene.we_tex.img.ptr = mlx_xpm_file_to_image(game->mlx.ptr, game->scene.we_tex.path, &game->texture.width, &game->texture.height);
	// game->scene.no_tex.img.data = (int *)mlx_get_data_addr(game->scene.no_tex.img.ptr,
	// 														&game->texture.img.bpp,
	// 														&game->texture.img.size,
	// 														&game->texture.img.endian
	// 													);
	// game->scene.so_tex.img.data = (int *)mlx_get_data_addr(game->scene.so_tex.img.ptr,
	// 														&game->texture.img.bpp,
	// 														&game->texture.img.size,
	// 														&game->texture.img.endian
	// 													);
	// game->scene.ea_tex.img.data = (int *)mlx_get_data_addr(game->scene.ea_tex.img.ptr,
	// 														&game->texture.img.bpp,
	// 														&game->texture.img.size,
	// 														&game->texture.img.endian
	// 													);
	// game->scene.we_tex.img.data = (int *)mlx_get_data_addr(game->scene.we_tex.img.ptr,
	// 														&game->texture.img.bpp,
	// 														&game->texture.img.size,
	// 														&game->texture.img.endian
	// 													);
	// int	i;
	// int	j;

	// i = -1;
	// while (game->map.grid[++i])
	// {
	// 	j = -1;
	// 	while (game->map.grid[i][++j])
	// 	{
	// 		// printf("grid[%d][%d] = %c\n", i, j, game->map.grid[i][j]);
	// 		if (game->map.grid[i][j] == '1')
	// 		{
	// 			// game->scene.no_tex.img.ptr = mlx_new_image(game->mlx.ptr, 1920, 1080);
	// 			// game->scene.no_tex.img.data = (int *)mlx_get_data_addr(game->scene.no_tex.img.ptr,
	// 			// 						&game->texture.img.bpp,
	// 			// 						&game->texture.img.size,
	// 			// 						&game->texture.img.endian
	// 			// 						);
	// 			mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->scene.so_tex.img.ptr, j * game->map.px, i * game->map.px);
	// 			// mlx_destroy_image(game->mlx.ptr, game->scene.so_tex.img.ptr);
	// 		}
	// 		else if (game->map.grid[i][j] == 'N')
	// 		{
	// 			// game->scene.so_tex.img.ptr = mlx_new_image(game->mlx.ptr, 1920, 1080);
	// 			// game->scene.so_tex.img.data = (int *)mlx_get_data_addr(game->scene.so_tex.img.ptr,
	// 			// 						&game->texture.img.bpp,
	// 			// 						&game->texture.img.size,
	// 			// 						&game->texture.img.endian
	// 			// 						);
	// 			mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->scene.no_tex.img.ptr, j * game->map.px, i * game->map.px);
	// 			// mlx_destroy_image(game->mlx.ptr, game->scene.no_tex.img.ptr);
	// 		}
	// 		else if (game->map.grid[i][j] == ' ')
	// 		{
	// 			// game->scene.so_tex.img.ptr = mlx_new_image(game->mlx.ptr, 1920, 1080);
	// 			// game->scene.we_tex.img.data = (int *)mlx_get_data_addr(game->scene.we_tex.img.ptr,
	// 			// 						&game->texture.img.bpp,
	// 			// 						&game->texture.img.size,
	// 			// 						&game->texture.img.endian
	// 			// 						);
	// 			mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->scene.no_tex.img.ptr, j * game->map.px, i * game->map.px);
	// 			// mlx_destroy_image(game->mlx.ptr, game->scene.no_tex.img.ptr);
	// 		}
	// 	}
	// }
	mlx_loop_hook(game->mlx.ptr, render_next_frame, game);
	mlx_key_hook(game->mlx.win, key_hook, &game);
	mlx_loop(game->mlx.ptr);
}

int	render_next_frame(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.grid[++i])
	{
		j = -1;
		while (game->map.grid[i][++j])
		{
			// printf("grid[%d][%d] = %c\n", i, j, game->map.grid[i][j]);
			if (game->map.grid[i][j] == '1')
			{
				// game->scene.no_tex.img.ptr = mlx_new_image(game->mlx.ptr, 1920, 1080);
				game->scene.no_tex.img.data = (int *)mlx_get_data_addr(game->scene.no_tex.img.ptr,
										&game->texture.img.bpp,
										&game->texture.img.size,
										&game->texture.img.endian
										);
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->scene.so_tex.img.ptr, j * game->map.px, i * game->map.px);
				// mlx_destroy_image(game->mlx.ptr, game->scene.so_tex.img.ptr);
			}
			else if (game->map.grid[i][j] == 'N')
			{
				// game->scene.so_tex.img.ptr = mlx_new_image(game->mlx.ptr, 1920, 1080);
				game->scene.so_tex.img.data = (int *)mlx_get_data_addr(game->scene.so_tex.img.ptr,
										&game->texture.img.bpp,
										&game->texture.img.size,
										&game->texture.img.endian
										);
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->scene.no_tex.img.ptr, j * game->map.px, i * game->map.px);
				// mlx_destroy_image(game->mlx.ptr, game->scene.no_tex.img.ptr);
			}
		}
	}
	game->mlx.img.ptr = mlx_new_image(game->mlx.ptr, game->map.width, game->map.height);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.ptr,
								&game->mlx.img.bpp,
								&game->mlx.img.size,
								&game->mlx.img.endian
								);
	update(game);
	mlx_put_image_to_window(game->mlx.ptr,
							game->mlx.win,
							game->mlx.img.ptr,
							0,
							0);
	mlx_destroy_image(game->mlx.ptr, game->mlx.img.ptr);
	return (1);
}