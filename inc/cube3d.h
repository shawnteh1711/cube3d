/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:17:02 by steh              #+#    #+#             */
/*   Updated: 2022/10/10 19:16:25 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../inc/struct.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "mlx.h"
# include <math.h>

// check.c
int		check_file(char **argv);
void	check_map(t_map *map);
void	check_tab(char *line);
void	check_newline(char *line);

// check2.c
int		check_file_extension(char *filename, char *ck_ext);
int		check_file_exits(char *filename);

// check_texture.c
void	ck_map(t_game *game);
void	ck_texture(char *texture, char *desc);
void	ck_color(t_color *color, char *color_name);


// check_map.c
void	check_first_last_row(t_map *map);
void	check_middle_row(t_map *map);
void	check_unwanted_char(t_map *map);


// get_map.c
void	get_map(int fd, char *line, t_map *map);
void	get_data(char **strs, t_scene *scene);
char**	copy_map(int fd, char *line);
void	get_texture(char *texture_path, t_texture *texture);
void	get_color(char *color_path, t_color *color);


// get_map2.c
void	extract_dimension(t_map *map);
void	get_file(int fd, t_game *game);

// utils.c
int		is_map(char *line);
void	free_strs(char **strs);
char	*ft_strdup2(const char *src, size_t col_num);
int		is_str_digit(char *c);

// utils2.c
void	ft_exit(char *s, t_map *map);

// utils3.c
double	deg_to_rad(double deg);
int		create_argb(int a, int r, int g, int b);

// control.c
int		key_hook(int keycode, t_map *map);

// init.c
void	init(t_game *game);

// init_game.c
void	init_game(t_game *game);
void	init_map(t_game *game);
int		render_next_frame(t_game *game);
void	init_player(t_game *game);
void	player_start_position(t_player *player, char **grid);
double	get_starting_orientation(char orientation);


// init_sprite.c
void	init_sprites(t_game *game);
void	get_map_items(t_scene *scene, t_map *map);
void	add_sprite(t_scene *scene, int x, int y);


// init_events.c
void	init_events(t_game *game);
int		key_pressed(int keycode, t_game *game);
int		key_released(int keycode, t_game *game);
int		close_window_cross(int keycode, t_game *game);

// update_game.c
void	update(t_game *game);

#endif
