/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:17:02 by steh              #+#    #+#             */
/*   Updated: 2022/10/07 17:04:39 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_texture
{
	char		*path;
}				t_texture;

typedef struct s_scene
{
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;
	t_texture	ea_tex;
	t_color		floor_color;
	t_color		ceiling_color;
}				t_scene;

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	int			error;
	int			position;
}				t_map;
typedef struct s_game
{
	t_scene		scene;
	t_map		map;
}				t_game;

#endif
