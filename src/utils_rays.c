/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:54:07 by steh              #+#    #+#             */
/*   Updated: 2022/12/22 21:07:31 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

/**
 * @brief check if player is looking south
 * if player is between 0 and 180, it is south
 * 
 * @param angle 
 * @return int 
 */
int	is_south(double angle)
{
	if (0 <= angle && angle < M_PI)
		return (1);
	else
		return (0);
}

/**
 * @brief check if player is looking west
 * if angle is between 90 and 270, looking west
 * 
 * @param angle 
 * @return int 
 */
int	is_west(double angle)
{
	if (M_PI / 2 <= angle && angle < M_PI * 1.5)
		return (1);
	else
		return (0);
}

/**
 * @brief Get the wall orientation object
 * handling the wall orientation at the corners
 * if x == 0 wall is facing us in the easterly direction
 * if x == width wall is facing us in the westerly direc
 * if y == 0 wall is facing us in southerly direc
 * if y == height wall is facing us in northerly direction
 * if horizontal ray is chosen and we are looking south
 * wall is facing north towards us
 * else if looking north wall is facing south towards us
 * same for vertical ray
 * 
 * @param map 
 * @param x 
 * @param y 
 * @param ray 
 * @return char 
 */
char	get_wall_orientation(t_map *map, int x, int y, t_ray *ray)
{
	if (x == 0)
		return ('E');
	else if (x == map->width)
		return ('W');
	else if (y == 0)
		return ('S');
	else if (y == map->height - 1)
		return ('N');
	if (ray->side == 'H')
	{
		if (map->grid[y - 1][x] != '1' && is_south(ray->angle))
			return ('N');
		else if (map->grid[y + 1][x] != '1' && !is_south(ray->angle))
			return ('S');
	}
	else
	{
		if (map->grid[y][x - 1] != '1' && !is_west(ray->angle))
			return ('W');
		else if (map->grid[y][x + 1] != '1' && is_west(ray->angle))
			return ('E');
	}
	return (0);
}

/**
 * @brief checks if the x and y position is outside the map
 * if yes return max int so ray is not chosen
 * if ray has at max height, return ray obstacle as 1
 * and orientation as north
 * if ray has hit a wall or door, find the correction orientation
 * of the wall to be drawn
 * 
 * @param map 
 * @param x 
 * @param y 
 * @param ray 
 * @return int 
 */
int	is_wall(t_map *map, double x, double y, t_ray *ray)
{
	ray->x = x;
	ray->y = y;
	if ((int)x < 0 || map->width < (int)x || (int)y < 0 || map->height < (int)y)
	{
		ray->size = INT_MAX;
		return (1);
	}
	if (map->height == (int)y)
	{
		ray->obstacle = '1';
		ray->orientation = 'N';
		return (1);
	}
	ray->obstacle = map->grid[(int)y][(int)x];
	if (ray->obstacle == '1')
	{
		ray->orientation = get_wall_orientation(map, (int)x, (int)y, ray);
		return (1);
	}
	if (ray->obstacle == 'D' && map->door_st == DOOR_CLOSE)
	{
		ray->orientation = 'D';
		return (1);
	}
	return (0);
}
