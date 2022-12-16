/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:58:59 by steh              #+#    #+#             */
/*   Updated: 2022/12/15 19:32:12 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	put_anime(t_game *game, int frame, int *i)
{
	if (frame > 5)
	{
		frame = 0;
		(*i) = 0;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win,
		(game->anime.images)[frame].ptr,
		game->mlx.win_w / 2 - (180),
		game->mlx.win_h - (450));
	(*i)++;
}

void	set_anime(t_game *game, int frame, int *i)
{
	put_anime(game, frame, i);
}

void	sprite(t_game *game)
{
	static int	i;

	if (i < 60)
		put_anime(game, 0, &i);
	else if (i >= 60 && i < 120)
		set_anime(game, 1, &i);
	else if (i >= 120 && i < 180)
		set_anime(game, 2, &i);
	else if (i >= 180 && i < 240)
		set_anime(game, 3, &i);
	else if (i >= 240 && i < 300)
		set_anime(game, 4, &i);
	else if (i >= 300 && i < 360)
		set_anime(game, 5, &i);
	else
		i = 0;
}
