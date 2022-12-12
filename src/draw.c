/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:32:08 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 16:56:14 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

void	draw(t_game *game)
{
	draw_ceilling(game);
	draw_floor(game);
	draw_walls(game);
	draw_mini_map(game);
}
