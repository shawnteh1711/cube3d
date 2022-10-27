/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:55:07 by steh              #+#    #+#             */
/*   Updated: 2022/10/26 15:16:04 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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