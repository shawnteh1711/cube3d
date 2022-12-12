/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:01:06 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 17:00:12 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

void	init(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->scene.floor_color.r = -1;
	game->scene.floor_color.g = -1;
	game->scene.floor_color.b = -1;
	game->scene.ceiling_color.r = -1;
	game->scene.ceiling_color.g = -1;
	game->scene.ceiling_color.b = -1;
}
