/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:15 by steh              #+#    #+#             */
/*   Updated: 2022/12/20 16:12:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

static int	check_corner_forward(t_player *p, char **g, int b_x, int b_y)
{
	double	angle;

	angle = normalize_radian(p->rotate_angle);
	if (angle >= 0 && angle <= (0.5 * M_PI))
	{
		return (first_quadrant(p, g, b_x, b_y));
	}
	else if (angle >= (0.5 * M_PI) && angle <= M_PI)
	{
		return (second_quadrant(p, g, b_x, b_y));
	}
	else if (angle >= M_PI && angle <= (M_PI * 1.5))
	{
		return (third_quadrant(p, g, b_x, b_y));
	}
	else if (angle >= (1.5 * M_PI) && angle <= (2 * M_PI))
	{
		return (fourth_quadrant(p, g, b_x, b_y));
	}
	return (0);
}

static int	check_corner_backward(t_player *p, char **g, int b_x, int b_y)
{
	double	angle;

	angle = normalize_radian(p->rotate_angle);
	if (angle >= M_PI && angle <= (M_PI * 1.5))
	{
		return (first_quadrant(p, g, b_x, b_y));
	}
	else if (angle >= (1.5 * M_PI) && angle <= (2 * M_PI))
	{
		return (second_quadrant(p, g, b_x, b_y));
	}
	else if (angle >= 0 && angle <= (0.5 * M_PI))
	{
		return (third_quadrant(p, g, b_x, b_y));
	}
	else if (angle >= (0.5 * M_PI) && angle <= M_PI)
	{
		return (fourth_quadrant(p, g, b_x, b_y));
	}
	return (0);
}

int check_corner(t_player *p, char **g)
{
    if (p->walk_direction == 'w')
        return (check_corner_forward(p, g, p->b_x, p->b_y));
    else if (p->walk_direction == 's')
        return (check_corner_backward(p, g, p->b_x, p->b_y));
    return (0);
}