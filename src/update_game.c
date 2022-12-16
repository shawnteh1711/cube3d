/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:15 by steh              #+#    #+#             */
/*   Updated: 2022/12/16 15:49:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

// 0 IS CLOSE
void	update_player_position(t_player *player, char **grid)
{
	double	move_step;
	double	rotation;

	if (player->walk_direction == 0)
		return ;
	move_step = player->speed;
	rotation = player->rotate_angle;
	if (player->walk_direction == 's')
		move_step = (-1) * player->speed;
	else if (player->walk_direction == 'a')
	{
		move_step = (-1) * player->speed;
		rotation = player->rotate_angle + deg_to_rad(90);
	}
	else if (player->walk_direction == 'd')
		rotation = player->rotate_angle + deg_to_rad(90);
	player->x += cos(rotation) * move_step;
	player->y += sin(rotation) * move_step;
	if (player->door_s == DOOR_OPEN && ft_strchr("12", grid[(int)player->y][(int)player->x]))
	{
		player->x -= cos(rotation) * move_step;
		player->y -= sin(rotation) * move_step;
	}
	else if (player->door_s == DOOR_CLOSE && ft_strchr("12D", grid[(int)player->y][(int)player->x]))
	{
		player->x -= cos(rotation) * move_step;
		player->y -= sin(rotation) * move_step;
	}
	
}

void	update_player_orientation(t_player *player)
{
	double	rotation;

	if (player->turn_direction == 0)
		return ;
	rotation = player->turn_direction * player->speed;
	player->rotate_angle += rotation;
}

void	cast_ray(t_ray *ray, t_map *map, t_player *player)
{
	t_ray	hrzn_intersection;
	t_ray	vrtl_intersection;

	hrzn_intersection.angle = normalize_radian(ray->angle);
	vrtl_intersection.angle = normalize_radian(ray->angle);
	hrzn_intersection.side = 'H';
	vrtl_intersection.side = 'V';
	get_hrzn_intersection(&hrzn_intersection, map, player);
	get_vrtl_intersection(&vrtl_intersection, map, player);
	if (hrzn_intersection.size <= vrtl_intersection.size)
		*ray = hrzn_intersection;
	else
		*ray = vrtl_intersection;
}

void	update_rays(t_game *game)
{
	double	ray_angle;
	int		i;

	game->map.door_st = game->player.door_s;
	ray_angle = game->player.rotate_angle - game->rays.view_angle / 2;
	i = -1;
	while (++i < game->mlx.win_w)
	// while (++i < game->map.width)
	{
		game->rays.arr[i].angle = ray_angle;
		cast_ray(&game->rays.arr[i], &game->map, &game->player);
		ray_angle += game->rays.view_angle / game->mlx.win_w;
	}
}


void	update_sprite_visibility(t_game *game)
{
	double		delta_angle;

	delta_angle = game->door.rotate_angle + game->player.rotate_angle;
	delta_angle = game->player.rotate_angle - delta_angle;
	if (delta_angle < -M_PI)
		delta_angle += 2.0 * M_PI;
	if (delta_angle > M_PI)
		delta_angle -= 2.0 * M_PI;
	delta_angle = fabs(delta_angle);
	if (delta_angle < game->rays.view_angle / 2 + deg_to_rad(4))
		game->door.visible = 1;
	else
		game->door.visible = 0;
}

void	update(t_game *game)
{
	update_player_position(&game->player, game->map.grid);
	update_player_orientation(&game->player);
	update_rays(game);
	update_sprite_visibility(game);
}
