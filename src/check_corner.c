/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_corner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:15 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:42:30 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief check if clipping through corner when moving forward
 * have to check each quadrant
 * check if wall exists in the left and right 
 * 
 * @param p player
 * @param g grid
 * @param b_x old player pos
 * @param b_y old player pos
 * @return int 
 */
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

/**
 * @brief check if clipping through corner when moving backward
 * have to check each quadrant
 * check if wall exists in the left and right 
 * 
 * @param p player
 * @param g grid
 * @param b_x old player pos
 * @param b_y old player pos
 * @return int 
 */
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

/**
 * @brief calls the appropriate function depending on
 * walk direction 
 * 
 * @param p 
 * @param g 
 * @return int 
 */
int	check_corner(t_player *p, char **g)
{
	if (p->walk_direction == 'w')
		return (check_corner_forward(p, g, p->b_x, p->b_y));
	else if (p->walk_direction == 's')
		return (check_corner_backward(p, g, p->b_x, p->b_y));
	return (0);
}

/**
 * @brief check if player colliding with door/wall
 * also checks if players clipping through corners
 * in between walls
 * if collide, reverse the player movement 
 * 
 * @param player 
 * @param grid 
 * @param rotation 
 * @param move_step 
 */
void	wall_collision(t_player *player, char **grid,
		double rotation, double move_step)
{
	if (player->door_s == DOOR_CLOSE
		&& (ft_strchr("1D", grid[(int)player->y][(int)player->x])
		|| check_corner(player, grid)))
	{
		player->x -= cos(rotation) * move_step;
		player->y -= sin(rotation) * move_step;
	}
	else if (player->door_s == DOOR_OPEN
		&& (ft_strchr("1", grid[(int)player->y][(int)player->x])
		|| check_corner(player, grid)))
	{
		player->x -= cos(rotation) * move_step;
		player->y -= sin(rotation) * move_step;
	}
}
