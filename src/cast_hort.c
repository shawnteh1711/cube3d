/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_hort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:01:28 by steh              #+#    #+#             */
/*   Updated: 2022/10/20 16:01:38 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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