/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:58:59 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 17:30:34 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	put_anime(t_game *game, int *frame, int *i)
{
	if (*frame > 5)
	{
		*frame = 0;
		(*i) = 0;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win,
		(game->anime.images)[*frame].ptr,
		game->mlx.win_w / 2 - (180),
		game->mlx.win_h - (320));
	(*i)++;
}

void	set_anime(t_game *game, int *frame, int *i)
{
	(*frame)++;
	put_anime(game, frame, i);
}

void	sprite(t_game *game)
{
	static int	i;
	static int	frame;

	if (i < 30)
		put_anime(game, &frame, &i);
	else if (i >= 30 && i < 60)
		set_anime(game, &frame, &i);
	else if (i >= 60 && i < 90)
		set_anime(game, &frame, &i);
	else if (i >= 90 && i < 120)
		set_anime(game, &frame, &i);
	else if (i >= 120 && i < 150)
		set_anime(game, &frame, &i);
	else if (i >= 150)
		set_anime(game, &frame, &i);
	else
		i = 0;
}
