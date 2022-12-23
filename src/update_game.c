/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:15 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:49:24 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief gets the updated:
 * position of player
 * orientation of player
 * new ray orientation
 * update mouse status in the case that m is pressed
 * 
 * @param game 
 */
void	update(t_game *game)
{
	update_player_position(&game->player, game->map.grid);
	update_player_orientation(&game->player);
	update_rays(game);
	update_mouse(game);
}
