/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:00:16 by steh              #+#    #+#             */
/*   Updated: 2022/10/20 16:00:29 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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
