/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:32:08 by steh              #+#    #+#             */
/*   Updated: 2022/12/22 21:23:01 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief draw ceiling
 * draw floor
 * draw walls
 * draw minimap
 * ceiling and floor first because they are the background
 * then draw walls
 * then draw mini map above everything
 * 
 * 
 * @param game 
 */
void	draw(t_game *game)
{
	draw_ceilling(game);
	draw_floor(game);
	draw_walls(game);
	draw_mini_map(game);
}
