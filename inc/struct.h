/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:17:02 by steh              #+#    #+#             */
/*   Updated: 2022/12/20 20:01:02 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>

# define MINIMAP_RATIO 200
# define MINIMAP_OFFSET 10
# define VIEW_ANGLE 60
# define SCALE 64
# define DOOR_CLOSE 0
# define DOOR_OPEN 1
# define WIN_W 1280
# define WIN_H 800

# ifndef OS
#  define K_ESC 53
#  define K_M 46
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_LEFT_ARROW 123
#  define K_RIGHT_ARROW 124
#  define K_SP 49
# else
#  define K_ESC 65307
#  define K_W 122
#  define K_A 113
#  define K_S 115
#  define K_D 100
#  define K_LEFT_ARROW 65361
#  define K_RIGHT_ARROW 65363
#  define K_SP 32
# endif

# ifndef OS
#  define DESTROY_NOTIFY 17
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
#  define M_DESTROY_NOTIFY 131072
#  define M_KEY_PRESS 1
#  define M_KEY_RELEASE 2
# else
#  define DESTROY_NOTIFY 33
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
#  define M_DESTROY_NOTIFY 0
#  define M_KEY_PRESS 1
#  define M_KEY_RELEASE 2
# endif

/* sprite animation paths */
# define SPRITE0 "./img/worm1.xpm"
# define SPRITE1 "./img/worm2.xpm"
# define SPRITE2 "./img/worm3.xpm"
# define SPRITE3 "./img/worm4.xpm"
# define SPRITE4 "./img/worm5.xpm"
# define SPRITE5 "./img/worm6.xpm"

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			argb;
}				t_color;

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct s_texture
{
	char		*path;
	t_img		img;
	int			width;
	int			height;
}				t_texture;

typedef struct s_sprite
{
	double		x;
	double		y;
	t_texture	tex;
	double		dist;
	double		rotate_angle;
	int			visible;
}				t_sprite;

typedef struct s_identifier
{
	const char	*identifier;
	void		*data;
}				t_identifier;

typedef struct s_scene
{
	t_texture		no_tex;
	t_texture		so_tex;
	t_texture		we_tex;
	t_texture		ea_tex;
	t_texture		do_tex;
	t_texture		pacman;
	t_color			floor_color;
	t_color			ceiling_color;
	t_texture		sprite_tex;
	int				total_sprites;
	int				mini_map_tile_size;
	t_sprite		*sprites;
	t_identifier	identifier;
}				t_scene;

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	int			error;
	int			position;
	int			px;
	int			door_st;
	int			door_count;
}				t_map;

typedef struct s_mlx
{
	void		*ptr;
	double		win_w;
	double		win_h;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct s_player
{
	double		x;
	double		y;
	int			b_x;
	int			b_y;
	double		rad;
	char		walk_direction;
	double		speed;
	int			turn_direction;
	double		rotate_angle;
	double		rotate_speed;
	int			door_s;
}				t_player;

typedef struct s_ray
{
	double		x;
	double		y;
	double		size;
	char		obstacle;
	double		angle;
	char		orientation;
	char		side;
	double		x_step;
	double		y_step;
}				t_ray;

typedef struct s_rays
{
	t_ray		*arr;
	double		view_angle;
	double		dist_proj_plane;
	char		orientation;
}				t_rays;

typedef struct s_rect
{
	int			x;
	int			y;
	double		width;
	double		height;
	int			fill_color;
	int			border_color;
	int			border_width;
	t_texture	tex;
	t_sprite	*sprite;
}				t_rect;

typedef struct s_circle
{
	int			x;
	int			y;
	double		radius;
	int			fill_color;
	int			border_color;
	int			border_width;
}				t_circle;

typedef struct s_line
{
	int			begin_x;
	int			begin_y;
	int			end_x;
	int			end_y;
	int			color;
	int			width;
}				t_line;

typedef struct s_animation
{
	t_img		*images;
}				t_animation;

typedef struct s_game
{
	t_scene		scene;
	t_map		map;
	t_mlx		mlx;
	t_texture	texture;
	t_img		img;
	t_player	player;
	t_sprite	sprite;
	t_rays		rays;
	t_sprite	door;
	t_animation	anime;
	int			prev_mouse_x;
	int			mouse_s;
	int			music;
}				t_game;

#endif
