/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:54:07 by steh              #+#    #+#             */
/*   Updated: 2022/10/27 17:53:47 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		is_south(double angle)
{
	if (0 <= angle && angle < M_PI)
		return (1);
	else
		return (0);
}

int		is_west(double angle)
{
	if (M_PI / 2 <= angle && angle < M_PI * 1.5)
		return (1);
	else
		return (0);
}


char	get_wall_orientation(t_map *map, int x, int y, t_ray *ray)
{
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	if (x == 0)
		return ('E');
	// else if (x == (int)ft_strlen_cube3d(map->grid[(int)y]) - 1)
	// 	return ('W');
	else if (x == map->width)
		return ('W');
	else if (y == 0)
		return ('S');
	else if (y == map->height - 1)
		return ('N');
	if (ray->side == 'H')
	{
		printf("wall x: %d\n", x);
		printf("wall y: %d\n", y);
		// printf("ray->side: %c\n", ray->side);
		printf("ray->angle: %f\n", ray->angle);
		// printf("map->grid[%d][%d] = %c\n", y-1, x, map->grid[y-1][x]);
		// printf("map->grid[%d][%d] = %c\n", y+1, x, map->grid[y+1][x]);
		if (map->grid[y - 1][x] != '1' && is_south(ray->angle))
			return ('N');
		// else if (map->grid[y + 1][x - 1] != '1' && !is_south(ray->angle))
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

int		is_wall(t_map *map, double x, double y, t_ray *ray)
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
	printf("obstacles: %c\n", ray->obstacle);
	printf("y: %f\n", y);
	printf("x: %f\n", x);
	printf("height: %d\n", map->height);
	printf("widtht: %d\n", map->width);
	ray->obstacle = map->grid[(int)y][(int)x];
	if (ray->obstacle == '1')
	{
		printf("inside obstacles: %c\n", ray->obstacle);
		printf("inside orientation: %d\n", ray->orientation);
		printf("inside y: %f\n", y);
		printf("inside x: %f\n", x);
		printf("inside height: %d\n", map->height);
		printf("inside widtht: %d\n", map->width);
		ray->orientation = get_wall_orientation(map, (int)x, (int)y, ray);
		return (1);
	}
	return (0);
}