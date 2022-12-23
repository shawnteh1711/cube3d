/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:58:59 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 15:10:11 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief For a period of time, display different image on the screen.
 * For example, for i between 1 to 60, put image 0 to the window.
 * Also pass &i into function to keep increment
 * 
 * @param game struct that store the array of anime images.
 */
void	sprite(t_game *game)
{
	static int	i;

	if (i < 60)
		put_anime(game, 0, &i);
	else if (i >= 60 && i < 120)
		put_anime(game, 1, &i);
	else if (i >= 120 && i < 180)
		put_anime(game, 2, &i);
	else if (i >= 180 && i < 240)
		put_anime(game, 3, &i);
	else if (i >= 240 && i < 300)
		put_anime(game, 4, &i);
	else if (i >= 300 && i < 360)
		put_anime(game, 5, &i);
	else
		i = 0;
}

/**
 * @brief put each image based on number of frame from 0 to 5
 * if frame is more than 5, return it to 0. Reset i(timer) back to 0.
 * keep increase i as timer.
 * 
 * @param game 
 * @param frame 
 * @param i 
 */
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
