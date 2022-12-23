/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:23:33 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:11:51 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief iterate from -1 to the width and height, and filling 
 * the colour accordingly
 * https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
 * 
 * @param rect rect struct with x and y values
 * @param img 
 * @param res_width width of the screen
 */
void	draw_rect(t_rect *rect, int *img, int res_width)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	rect->border_width--;
	i = -1;
	while (++i < rect->height)
	{
		j = -1;
		while (++j < rect->width)
		{
			tmp_x = rect->x + j;
			tmp_y = rect->y + i;
			if (i <= rect->border_width || j <= rect->border_width
				|| i >= rect->height - 1 - rect->border_width
				|| j >= rect->width - 1 - rect->border_width)
				img[tmp_y * res_width + tmp_x] = rect->border_color;
			else
				img[tmp_y * res_width + tmp_x] = rect->fill_color;
		}
	}
}

/**
 * @brief find the diff in x and y
 * find the line length
 * find the change in x and y per pixel
 * put colour in pixels and increment and increment
 * https://gontjarow.github.io/MiniLibX/mlx-tutorial-draw-line.html
 * 
 * @param line 
 * @param img 
 * @param res_width 
 */
void	draw_line(t_line *line, int *img, int res_width)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = line->end_x - line->begin_x;
	delta_y = line->end_y - line->begin_y;
	pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line->begin_x;
	pixel_y = line->begin_y;
	while (pixels)
	{
		img[(int)pixel_y * res_width + (int)pixel_x] = line->color;
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

/**
 * @brief find the x position and y position using trigo
 * add the x and y to the current x and y pos
 * put the colour
 * increment angle by 0.1
 * http://www.softwareandfinance.com/Turbo_C/DrawCircle.html
 * 
 * @param circle 
 * @param img 
 * @param res_width 
 */
void	draw_circle(t_circle *circle, int *img, int res_width)
{
	double	angle;
	double	x1;
	double	y1;
	int		tmp_x;
	int		tmp_y;

	angle = 0;
	while (angle <= 360)
	{
		x1 = circle->radius * cos(deg_to_rad(angle));
		y1 = circle->radius * sin(deg_to_rad(angle));
		tmp_x = circle->x + (int)x1;
		tmp_y = circle->y + (int)y1;
		img[tmp_y * res_width + tmp_x] = circle->fill_color;
		angle += 0.1;
	}
}
