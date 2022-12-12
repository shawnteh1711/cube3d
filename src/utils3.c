/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:25 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 17:34:23 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

// produce following
// AAAAAAAA000000000000000000000000
//         RRRRRRRR0000000000000000
//                 GGGGGGGG00000000
//                         BBBBBBBB
// --------------------------------
// AAAAAAAARRRRRRRRGGGGGGGGBBBBBBBB
int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

double	normalize_radian(double radian)
{
	double	full_circle;

	full_circle = deg_to_rad(360);
	radian = fmod(radian, full_circle);
	if (radian < 0)
		radian += full_circle;
	return (radian);
}
