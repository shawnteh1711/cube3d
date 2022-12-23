/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:56:07 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:49:31 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief save the old pos of the player
 * if w a s d is not pressed, return
 * if s is pressed move step is -ve (backward)
 * if w is pressed move step is +ve (forward)
 * if a is pressed move step is -ve (left)
 * if d is pressed move step is +ve (right)
 * cos to find movement in the x axis
 * sin to find movement in the y axis
 * check if collide with wall
 * 
 * @param player 
 * @param grid 
 */
void	update_player_position(t_player *player, char **grid)
{
	double	move_step;
	double	rotation;

	player->b_x = (int)player->x;
	player->b_y = (int)player->y;
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
	wall_collision(player, grid, rotation, move_step);
}

/**
 * @brief if no rotation return
 * rotation is the turn direction * player speed
 * if +ve clockwise, if -ve anti
 * rotate angle + rotation to find updated orientation
 * 
 * @param player 
 */
void	update_player_orientation(t_player *player)
{
	double	rotation;

	if (player->turn_direction == 0)
		return ;
	rotation = player->turn_direction * player->speed;
	player->rotate_angle += rotation;
}

/**
 * @brief normalize the angles to make it be 0-360
 * set horizontal side as 'H'
 * set vertical side as 'V'
 * get hrzn and vrtl intersection
 * the lowest size is chosen as the optimum ray
 * https://www.youtube.com/watch?v=eOCQfxRQ2pY
 * 
 * @param ray 
 * @param map 
 * @param player 
 */
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

/**
 * @brief get the left most ray angle
 * iterate through the screen width
 * cast ray in the angle
 * increment the angle according to the view angle and 
 * window width
 * 
 * @param game 
 */
void	update_rays(t_game *game)
{
	double	ray_angle;
	int		i;

	game->map.door_st = game->player.door_s;
	ray_angle = game->player.rotate_angle - game->rays.view_angle / 2;
	i = -1;
	while (++i < game->mlx.win_w)
	{
		game->rays.arr[i].angle = ray_angle;
		cast_ray(&game->rays.arr[i], &game->map, &game->player);
		ray_angle += game->rays.view_angle / game->mlx.win_w;
	}
}
