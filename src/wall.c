/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:26:29 by steh              #+#    #+#             */
/*   Updated: 2022/12/23 17:56:06 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief This is the main function for drawing the walls of the game world.
 * It loops through all of the rays that have been cast from the player's
 * position, and for each ray it calculates the height of the wall,
 * the position of the wall on the screen, and the texture to use for the wall.
 * It then calls the draw_wall_strip function to
 * draw a vertical strip of the wall texture to the screen.
 * 
 * @param game 
 */
void	draw_walls(t_game *game)
{
	int		i;
	double	wall_height;
	t_rect	rect;
	t_ray	*ray;

	i = -1;
	while (++i < game->mlx.win_w)
	{
		ray = &game->rays.arr[i];
		wall_height = get_wall_height(game, ray);
		rect.x = i;
		rect.y = get_y_wall_position(game, wall_height);
		rect.height = wall_height;
		rect.tex = get_wall_texture(&game->scene, ray->orientation);
		draw_wall_strip(&rect, game->mlx.img.data, &game->mlx, ray);
	}
}

/**
 * @brief This function calculates the height of a wall
 * based on the distance of the wall
 * from the player and the size of the wall.
 * It also applies a fisheye effect to the wall
 * height to simulate the distortion that occurs
 * when the player is looking at a wall at an angle.
 * goes from grid distance to full scale distance. 
 * The fisheye effect is applied by using the fisheye_adjustment factor 
 * to adjust the size of the wall relative to the distance
 * to the projection plane. 
 * When the player is looking straight at the wall,
 * the fisheye_adjustment factor is 1 
 * and the wall is rendered at its full size.
 * When the player is looking at the wall at an angle, 
 * the fisheye_adjustment factor is less than 1, 
 * which results in the wall being rendered smaller than its full size.
 * reference for fisheye adjustment:
 * https://www.permadi.com/tutorial/raycast/rayc8.html
 * @param game 
 * @param ray 
 * @return double 
 */
double	get_wall_height(t_game *game, t_ray *ray)
{
	double	wall_height;
	double	scaled_distance;
	double	fisheye_adjustment;

	fisheye_adjustment = cos(ray->angle - game->player.rotate_angle);
	scaled_distance = ray->size * SCALE * fisheye_adjustment;
	wall_height = (SCALE / (scaled_distance)) * game->rays.dist_proj_plane;
	return (wall_height);
}

/**
 * @brief This function calculates the vertical position of a wall on the screen 
 * based on the height of the wall and the height of the screen. 
 * It centers the wall on the screen vertically.
 * Get the y wall position
 * find the center of the screen
 * find the center of the wall
 * get the top of the wall y position
 * 
 * @param game 
 * @param wall_height 
 * @return int 
 */
int	get_y_wall_position(t_game *game, double wall_height)
{
	double	center_screen;
	double	center_wall;
	int		y;

	center_screen = game->mlx.win_h / 2;
	center_wall = wall_height / 2;
	y = center_screen - center_wall;
	if (y < 0)
		y = 0;
	return (y);
}

/**
 * @brief This function draws a vertical strip of a 
 * wall texture to the screen at the given position.
 * It uses the get_bitmap_offset function to determine 
 * which pixel in the texture 
 * to use based on the position of the ray that hit 
 * the wall.
 * 
 * 1. It calculates the step value, which represents the
 * vertical distance between pixels in the wall texture.
 * This is done by dividing the height of the wall texture
 * by the height of the wall on the screen.
 * 
 * 2. It then initializes the tex_pox variable to the
 * vertical position of the middle of the wall texture
 * relative to the top of the screen.
 * This is done by calculating the vertical distance 
 * between the top of the screen and the middle of the wall,
 * and then multiplying this distance by the step value.
 *
 * 3. It calls the get_bitmap_offset function to calculate the
 * horizontal offset value for the wall texture based on the
 * position of the ray that hit the wall. This offset value is
 * used to determine which pixel in the texture to use for
 * the wall strip.
 * 
 * 4. It then enters a loop that iterates over each pixel in
 * the wall strip. For each pixel, it calculates the vertical
 * position in the wall texture using the following line of code:
 * y_tex = (int)tex_pox & (rect->tex.height - 1);
 * The & operator is used to apply a bitwise AND operation
 * to the tex_pox value and the height of the wall texture minus 1.
 * This has the effect of wrapping the tex_pox value back to 0
 * when it exceeds the height of the wall texture.
 * This is necessary because the wall texture is tiled vertically,
 * so we want to use the same texture for the top and bottom
 * of the wall.
 * 
 * Finally, the function uses the y_tex and x_tex values to
 * index into the wall texture and retrieve the pixel color,
 * which it then draws to the screen using the following line of code:
 * img[(int)(rect->y * res->win_w) + (int)(y * res->win_w) + rect->x] 
 * = rect->tex.img.data[y_tex * rect->tex.height + x_tex];
 * The img array represents the pixel data for the screen,
 * and the rect->tex.img.data array represents the pixel data
 * for the wall texture. The y_tex and x_tex values are used to
 * index into the wall texture, and the resulting pixel color
 * is then written to the screen at the appropriate position.
 * 
 * draw the wall strip
 * the further the player is from the wall, the smaller the wall
 * divide to get the step to increment
 * find the texture position
 * find the texture pos in x
 * find the texture pos in y
 * increment the texture
 * put colour in image
 * 
 * @param rect 
 * @param img 
 * @param res 
 * @param ray 
 */
void	draw_wall_strip(t_rect *rect, int *img, t_mlx *res, t_ray *ray)
{
	int		y;
	int		y_tex;
	int		x_tex;
	double	step;
	double	tex_pox;

	step = 1.0 * rect->tex.height / rect->height;
	tex_pox = (rect->y - res->win_h / 2 + rect->height / 2) * step;
	x_tex = get_bitmap_offset(ray, rect->tex.width);
	y = -1;
	while (++y < rect->height && y < res->win_h)
	{
		y_tex = (int)tex_pox & (rect->tex.height - 1);
		tex_pox += step;
		img[(int)(rect->y * res->win_w) + (int)(y * res->win_w)
			+ rect->x] = rect->tex.img.data[y_tex * rect->tex.height + x_tex];
	}
}

/**
 * @brief 
 * This function calculates an offset value for a bitmap image
 * based on a given ray. The ray is represented by a t_ray
 * struct, which has two fields: x and y, which represent the
 * position of the ray, and side, which indicates whether the
 * ray has hit a horizontal or vertical wall.The function first
 * checks the value of side to determine whether the ray has
 * hit a horizontal or vertical wall. If the ray has hit a 
 * horizontal wall, it calculates the remainder of the x position
 * when divided by 1 (i.e., the fractional part of x)
 * and multiplies it by the width of the bitmap. If the ray has
 * hit a vertical wall, it does the same thing with the y position
 * instead. In either case, the result is returned as the offset
 * value for the bitmap. For example, suppose the bitmap has a
 * width of 64 and the ray has hit a horizontal wall at x = 1.75. 
 * The remainder of x when divided by 1 is 0.75,
 * so the offset value would be 64 * 0.75 = 48.
 * If the ray had hit a vertical wall at y = 2.25,
 * the offset value would be 64 * 0.25 = 16.
 * 
 * @param ray 
 * @param bitmap_width used to calculate the offset value for the image. 
 * The offset value determines which pixel in the bitmap
 * should be used to represent a given point on the wall that the 
 * ray has hit. For example, if the ray has hit a horizontal wall at x = 1.75, 
 * the fractional part of x (i.e., 0.75) is used to calculate the offset value, 
 * which is then used to determine which pixel in the bitmap should be used to
 * represent the point on the wall. The bitmap width is used to scale the 
 * fractional part of x or y, so that the offset value is in the range 0 
 * to (bitmap width - 1). This is necessary because the offset value is an 
 * integer and must be a valid index into the bitmap.
 * For example, if the bitmap width is 64, the offset
 * value must be in the range 0 to 63.
 * @return int 
 */
int	get_bitmap_offset(t_ray *ray, int bitmap_width)
{
	double	remainder;
	int		offset;

	if (ray->side == 'H')
	{
		remainder = ray->x - floor(ray->x);
		offset = bitmap_width * remainder;
	}
	else
	{
		remainder = ray->y - floor(ray->y);
		offset = bitmap_width * remainder;
	}
	return (offset);
}
