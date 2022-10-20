/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:28:25 by steh              #+#    #+#             */
/*   Updated: 2022/10/20 17:44:11 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../inc/struct.h"
# include "../inc/cube3d.h"



int draw_linesss(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (1);
}

int	render(t_game *game)
{
	game->mlx.img.ptr = mlx_new_image(game->mlx.ptr, game->mlx.win_w, game->mlx.win_h);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.ptr,
								&game->mlx.img.bpp,
								&game->mlx.img.size,
								&game->mlx.img.endian
								);
	update(game);
	draw(game);
	mlx_put_image_to_window(game->mlx.ptr,
						game->mlx.win,
						game->mlx.img.ptr,
						0,
						0);
	return (1);
}

void	minimap(t_game *game)
{
	mlx_loop_hook(game->mlx.ptr, render, game);
	mlx_key_hook(game->mlx.win, key_hook, game);
	mlx_loop(game->mlx.ptr);
}

void	set_rays(t_game *game)
{
	game->rays.arr = malloc(game->mlx.win_w * sizeof(t_ray));
	if (!game->rays.arr)
		exit(EXIT_SUCCESS);
	game->rays.view_angle = deg_to_rad(VIEW_ANGLE);
	game->rays.dist_proj_plane = (game->mlx.win_w / 2)
		/ tan(game->rays.view_angle / 2);
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
				player->y = i + 0.5;
				player->rotate_angle = get_starting_orientation(grid[i][j]);
				grid[i][j] = '0';
			}
		}
	}
}

void	ready_game(t_game *game)
{
	init_player(game);
	set_rays(game);
	init_others(game);

}

void	init_game(t_game *game)
{
	game->mlx.ptr = mlx_init();
	game->map.px = 64;
	game->mlx.win_w = game->map.width * game->map.px;
	game->mlx.win_h = game->map.height * game->map.px;
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->mlx.win_w, game->mlx.win_h, "cub3d");
	game->texture.width = 64;
	game->texture.height = 64;
	game->scene.no_tex.width = 64;
	game->scene.no_tex.height = 64;
	game->scene.so_tex.width = 64;
	game->scene.so_tex.height = 64;
	game->scene.we_tex.width = 64;
	game->scene.we_tex.height = 64;
	game->scene.ea_tex.width = 64;
	game->scene.ea_tex.height = 64;
	game->scene.sprite_tex.width = 64;
	game->scene.sprite_tex.height = 64;
	ready_game(game);
	minimap(game);
	// init_player(game);
	// init_events(game);
	// // init_sprites(game);
	// init_others(game);
}





void	load_texture(void *mlx, t_texture *texture)
{
	texture->img.ptr = mlx_xpm_file_to_image(mlx, texture->path,
			&texture->width, &texture->height);
	texture->img.data = (int *)mlx_get_data_addr(texture->img.ptr,
			&texture->img.bpp,
			&texture->img.size,
			&texture->img.endian);
}

void	put_player_image(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.grid[++i])
	{
		j = -1;
		while (game->map.grid[i][++j])
		{
			if (ft_strchr("NSEW", game->map.grid[i][j]))
			{
				game->player.x = j * game->map.px;
				game->player.y = i * game->map.px;
				game->player.rotate_angle = get_starting_orientation(game->map.grid[i][j]);
				game->rays.orientation = game->map.grid[i][j];
				printf("orintation: %c\n", game->rays.orientation);
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->scene.pacman.img.ptr, j * game->map.px, i * game->map.px);
			}
		}
	}
}

void	init_others(t_game *game)
{	
	game->scene.mini_map_tile_size = game->mlx.win_w/ MINIMAP_RATIO;
	set_rays(game);
	load_texture(game->mlx.ptr, &game->scene.no_tex);
	load_texture(game->mlx.ptr, &game->scene.so_tex);
	load_texture(game->mlx.ptr, &game->scene.we_tex);
	load_texture(game->mlx.ptr, &game->scene.ea_tex);
	game->scene.pacman.img.ptr = mlx_xpm_file_to_image(game->mlx.ptr, "./img/pacman.xpm",
		&game->scene.pacman.width, &game->scene.pacman.height);
	game->scene.pacman.img.data = (int *)mlx_get_data_addr(game->scene.pacman.img.ptr,
		&game->scene.pacman.img.bpp,
		&game->scene.pacman.img.size,
		&game->scene.pacman.img.endian);
	put_player_image(game);
}

t_texture	get_wall(t_scene *scene, char orientation)
{
	// printf("orintation: %c\n", orientation);
	if (orientation == 'N')
		return (scene->no_tex);
	else if (orientation == 'S')
		return (scene->so_tex);
	else if (orientation == 'E')
		return (scene->ea_tex);
	else
		return (scene->we_tex);
}

int	render_next_frame(t_game *game)
{
	int			i;
	int			j;
	t_texture tex;

	mlx_clear_window(game->mlx.ptr, game->mlx.win);
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
				tex = get_wall(&game->scene, game->rays.orientation);
				// printf("%s\n", tex.path);
				tex.img.data = (int *)mlx_get_data_addr(tex.img.ptr,
										&tex.img.bpp,
										&tex.img.size,
										&tex.img.endian
										);
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, tex.img.ptr, j * game->map.px, i * game->map.px);
				// mlx_destroy_image(game->mlx.ptr, game->scene.so_tex.img.ptr);
			}
			mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->scene.pacman.img.ptr, game->player.x, game->player.y);
		}
	}
	game->mlx.img.ptr = mlx_new_image(game->mlx.ptr, game->map.width, game->map.height);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.ptr,
								&game->mlx.img.bpp,
								&game->mlx.img.size,
								&game->mlx.img.endian
								);
	// update(game);
	// draw(game);
	mlx_put_image_to_window(game->mlx.ptr,
							game->mlx.win,
							game->mlx.img.ptr,
							0,
							0);
	mlx_destroy_image(game->mlx.ptr, game->mlx.img.ptr);
	return (1);
}
