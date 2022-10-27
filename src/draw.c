/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:32:08 by steh              #+#    #+#             */
/*   Updated: 2022/10/27 18:43:35 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	draw_rect(t_rect *rect, int *img, int res_width)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	rect->border_width--;
	i = -1;
	while (++i < rect->height)
	{
		j = -1;
		while (++j < rect->width)
		{
			tmp_x = rect->x + j;
			tmp_y = rect->y + i;
			if (i <= rect->border_width || j <= rect->border_width
				|| i >= rect->height - 1 - rect->border_width
				|| j >= rect->width - 1 - rect->border_width)
				img[tmp_y * res_width + tmp_x] = rect->border_color;
			else
				img[tmp_y * res_width + tmp_x] = rect->fill_color;
		}
	}
}

void	draw_ceilling(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = game->mlx.win_w;
	rect.height = game->mlx.win_h / 2;
	rect.border_width = 0;
	rect.fill_color = game->scene.ceiling_color.argb;
	draw_rect(&rect, game->mlx.img.data, game->mlx.win_w);
}

void	draw_floor(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = game->mlx.win_h / 2;
	rect.width = game->mlx.win_w;
	rect.height = game->mlx.win_h / 2;
	rect.border_width = 0;
	rect.fill_color = game->scene.floor_color.argb;
	draw_rect(&rect, game->mlx.img.data, game->mlx.win_w);
}

int		get_fill_color(t_color *floor_color, char grid_item)
{
	int	color;

	if (grid_item == '1')
		color = floor_color->argb;
	else if (grid_item == '2')
		color = 0x00fca311;
	else
		color = 0x00FFFFFF;
	return (color);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;
	char	grid_item;
	t_rect	rect;
	
	i = -1;
	while (game->map.grid[++i])
	{
		j = -1;
		while (game->map.grid[i][++j])
		{
			grid_item = game->map.grid[i][j];
			if (grid_item == ' ')
				continue ;
			rect.x = j * game->scene.mini_map_tile_size + MINIMAP_OFFSET;
			rect.y = i * game->scene.mini_map_tile_size + MINIMAP_OFFSET;
			rect.width = game->scene.mini_map_tile_size;
			rect.height = game->scene.mini_map_tile_size;
			rect.border_color = 0x0014213d;
			rect.border_width = 2;
			rect.fill_color = get_fill_color(&game->scene.floor_color, grid_item);
			draw_rect(&rect, game->mlx.img.data, game->mlx.win_w);
		}
	}
}


void	draw_line(t_line *line, int *img, int res_width)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = line->end_x - line->begin_x;
	delta_y = line->end_y - line->begin_y;
	pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line->begin_x;
	pixel_y = line->begin_y;
	while (pixels)
	{
		img[(int)pixel_y * res_width + (int)pixel_x] = line->color;
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	draw_rays(t_game *game, double tile_size)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < game->mlx.win_w)
	{
		line.begin_x = game->player.x * tile_size + MINIMAP_OFFSET;
		line.begin_y = game->player.y * tile_size + MINIMAP_OFFSET;
		line.end_x = game->player.x * tile_size + MINIMAP_OFFSET
			+ cos(game->rays.arr[i].angle)
			* tile_size * game->rays.arr[i].size;
		line.end_y = game->player.y * tile_size + MINIMAP_OFFSET
			+ sin(game->rays.arr[i].angle)
			* tile_size * game->rays.arr[i].size;
		line.color = 0x00F6B8BD;
		draw_line(&line, game->mlx.img.data, game->mlx.win_w);
	}
}

void	draw_circle(t_circle *circle, int *img, int res_width)
{
	double	angle;
	double	x1;
	double	y1;
	int		tmp_x;
	int		tmp_y;

	angle = 0;
	while (angle <= 360)
	{
		x1 = circle->radius * cos(deg_to_rad(angle));
		y1 = circle->radius * sin(deg_to_rad(angle));
		tmp_x = circle->x + (int)x1;
		tmp_y = circle->y + (int)y1;
		img[tmp_y * res_width + tmp_x] = circle->fill_color;
		angle += 0.1;
	}
}

void	draw_player(t_game *game, double tile_size)
{
	t_circle	circle;

	draw_rays(game, tile_size);
	game->player.rad = ceil(tile_size / 2);
	circle.x = game->player.x * tile_size + MINIMAP_OFFSET;
	circle.y = game->player.y * tile_size + MINIMAP_OFFSET;
	circle.radius = game->player.rad;
	circle.fill_color = 0x00e63946;
	while (circle.radius--)
		draw_circle(&circle, game->mlx.img.data, game->mlx.win_w);
}

void	draw_mini_map(t_game *game)
{
	int	height_mini_map;
	game->scene.mini_map_tile_size = game->mlx.win_w/ MINIMAP_RATIO;
	height_mini_map = game->scene.mini_map_tile_size * game->map.height
					+ MINIMAP_OFFSET * 2;
	if (height_mini_map > game->mlx.win_h)
		return ;
	draw_map(game);
	draw_player(game, game->scene.mini_map_tile_size);
}

int		get_bitmap_offset(t_ray *ray, int bitmap_width)
{
	double	remainder;
	int		offset;

	if (ray->side == 'H')
	{
		remainder = ray->x - floor(ray->x);
		offset = bitmap_width * remainder;
	}
	else
	{
		remainder = ray->y - floor(ray->y);
		offset = bitmap_width * remainder;
	}
	return (offset);
}


void	draw_wall_strip(t_rect *rect, int *img, t_mlx *res, t_ray *ray)
{
	int		y;
	int		y_tex;
	int		x_tex;
	double	step;
	double	tex_pox;

	step = 1.0 * rect->tex.height / rect->height;
	tex_pox = (rect->y - res->win_h / 2 + rect->height / 2) * step;
	x_tex = get_bitmap_offset(ray, rect->tex.width);
	y = -1;
	while (++y < rect->height && y < res->win_h)
	{
		y_tex = (int)tex_pox & (rect->tex.height - 1);
		tex_pox += step;
		img[(int)(rect->y * res->win_w) + (int)(y * res->win_w)
			+ rect->x] = rect->tex.img.data[y_tex * rect->tex.height + x_tex];
	}
}


t_texture	get_wall_texture(t_scene *scene, char orientation)
{
	if (orientation == 'N')
		return (scene->no_tex);
	else if (orientation == 'S')
		return (scene->so_tex);
	else if (orientation == 'E')
		return (scene->ea_tex);
	else
		return (scene->we_tex);
}

double		get_wall_height(t_game *game, t_ray *ray)
{
	double	wall_height;
	double	scaled_distance;
	double	fisheye_adjustment;

	fisheye_adjustment = cos(ray->angle - game->player.rotate_angle);
	scaled_distance = ray->size * SCALE * fisheye_adjustment;
	wall_height = (SCALE / (scaled_distance)) * game->rays.dist_proj_plane;
	return (wall_height);
}

int			get_y_wall_position(t_game *game, double wall_height)
{
	double	center_screen;
	double	center_wall;
	int		y;

	center_screen = game->mlx.win_h / 2;
	center_wall = wall_height / 2;
	y = center_screen - center_wall;
	if (y < 0)
		y = 0;
	return (y);
}

void		draw_walls(t_game *game)
{
	int		i;
	double	wall_height;
	t_rect	rect;
	t_ray	*ray;

	i = -1;
	while (++i < game->mlx.win_w)
	{
		ray = &game->rays.arr[i];
		wall_height = get_wall_height(game, ray);
		rect.x = i;
		rect.y = get_y_wall_position(game, wall_height);
		rect.height = wall_height;
		rect.tex = get_wall_texture(&game->scene, ray->orientation);
		draw_wall_strip(&rect, game->mlx.img.data, &game->mlx, ray);
	}
}

void	draw(t_game *game)
{
	draw_ceilling(game);
	draw_floor(game);
	draw_walls(game);
	draw_mini_map(game);
}