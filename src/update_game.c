/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:15 by steh              #+#    #+#             */
/*   Updated: 2022/12/20 19:55:53 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	update(t_game *game)
{
	update_player_position(&game->player, game->map.grid);
	update_player_orientation(&game->player);
	update_rays(game);
	update_sprite_visibility(game);
	update_mouse(game);
}
