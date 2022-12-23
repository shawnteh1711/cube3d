/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:14:07 by steh              #+#    #+#             */
/*   Updated: 2022/12/22 19:02:12 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief call render in a loop
 * 
 * @param game 
 */
void	render_game(t_game *game)
{
	mlx_loop_hook(game->mlx.ptr, render, game);
	mlx_loop(game->mlx.ptr);
}

/**
 * @brief clear the window at every loop
 * creates a new image
 * gets the data of the new image
 * update the game
 * draw the game
 * puts the image to the window
 * puts the animated sprite on the image
 * destroy image for the next loop
 * 
 * @param game 
 * @return int 
 */
int	render(t_game *game)
{
	mlx_clear_window(game->mlx.ptr, game->mlx.win);
	game->mlx.img.ptr = mlx_new_image(game->mlx.ptr, game->mlx.win_w,
			game->mlx.win_h);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.ptr,
			&game->mlx.img.bpp,
			&game->mlx.img.size,
			&game->mlx.img.endian
			);
	update(game);
	draw(game);
	mlx_put_image_to_window(game->mlx.ptr,
		game->mlx.win,
		game->mlx.img.ptr,
		0,
		0);
	sprite(game);
	mlx_destroy_image(game->mlx.ptr, game->mlx.img.ptr);
	return (1);
}
