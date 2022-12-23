/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_hort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:01:28 by steh              #+#    #+#             */
/*   Updated: 2022/12/22 20:53:41 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

/**
 * @brief Get the hrzn intersection 
 * if the angle is parallel to the x axis give it a max int so it 
 * is not chosen as the optimum ray
 * this is because there is no intersection when there is a parallel ray
 * check if south or north and use appropriate formula
 * 
 * @param ray 
 * @param map 
 * @param player 
 */
void	get_hrzn_intersection(t_ray *ray, t_map *map, t_player *player)
{
	ray->size = 0;
	if (ray->angle == deg_to_rad(180) || ray->angle == deg_to_rad(360))
	{
		ray->size = INT_MAX;
		return ;
	}
	if (is_south(ray->angle))
		get_hrzn_intersection_south(ray, map, player);
	else
		get_hrzn_intersection_north(ray, map, player);
}
