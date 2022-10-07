/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:17:02 by steh              #+#    #+#             */
/*   Updated: 2022/10/07 22:23:54 by steh             ###   ########.fr       */
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

// check.c
int		check_file(char **argv);
void	check_map(t_map *map);
void	check_tab(char *line);
void	check_newline(char *line);

// check2.c
int		check_file_extension(char *filename, char *ck_ext);
int		check_file_exits(char *filename);

// check_texture.c
void	ck_texture(t_game *game);


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


#endif
