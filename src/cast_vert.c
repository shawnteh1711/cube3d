/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:00:16 by steh              #+#    #+#             */
/*   Updated: 2022/12/22 20:54:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

/**
 * @brief Get the vert intersection 
 * if the angle is parallel to the y axis give it a max int so it 
 * is not chosen as the optimum ray
 * this is because there is no intersection when there is a parallel ray
 * check if west or east and use appropriate formula
 * 
 * @param ray 
 * @param map 
 * @param player 
 */
void	get_vrtl_intersection(t_ray *ray, t_map *map, t_player *player)
{
	ray->size = 0;
	if (ray->angle == deg_to_rad(90) || ray->angle == deg_to_rad(270))
	{
		ray->size = INT_MAX;
		return ;
	}
	if (is_west(ray->angle))
		get_vrtl_intersection_west(ray, map, player);
	else
		get_vrtl_intersection_east(ray, map, player);
}
