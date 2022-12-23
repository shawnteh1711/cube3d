/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:55:07 by steh              #+#    #+#             */
/*   Updated: 2022/12/22 20:39:16 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

/**
 * @brief Get the hrzn intersection south object 
 * get the closest grid value in y using ceil
 * y step is calculated 
 * x step is calculated using trigo 
 * get the closest grid value in x 
 * calucate the ray length using pythagoras
 * check if ray hit wall, if no cont
 * set y step as 1
 * find the corresponding x step
 * find the new ray length
 * loop finding the ray section until wall is hit
 * same is done for NORTH just the opposite direction
 * 
 * @param ray 
 * @param map 
 * @param player 
 */
void	get_hrzn_intersection_south(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_y = ceil(player->y);
	y_step = a_y - player->y;
	x_step = y_step / tan(ray->angle);
	a_x = player->x + x_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x, a_y, ray))
		return ;
	y_step = 1;
	x_step = y_step / tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x, a_y, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}

void	get_hrzn_intersection_north(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_y = floor(player->y);
	y_step = player->y - a_y;
	x_step = y_step / tan(ray->angle);
	a_x = player->x - x_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x, a_y - 1, ray))
		return ;
	y_step = -1;
	x_step = +y_step / tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x, a_y - 1, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}

/**
 * @brief same as hrztl just moving to the left/right 
 * x step is set to 1 or -1 depending on west or east
 * 
 * @param ray 
 * @param map 
 * @param player 
 */
void	get_vrtl_intersection_west(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_x = floor(player->x);
	x_step = player->x - a_x;
	y_step = x_step * tan(ray->angle);
	a_y = player->y - y_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x - 1, a_y, ray))
		return ;
	x_step = -1;
	y_step = x_step * tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x - 1, a_y, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}

void	get_vrtl_intersection_east(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_x = ceil(player->x);
	x_step = a_x - player->x;
	y_step = x_step * tan(ray->angle);
	a_y = player->y + y_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x, a_y, ray))
		return ;
	x_step = 1;
	y_step = x_step * tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x, a_y, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}
