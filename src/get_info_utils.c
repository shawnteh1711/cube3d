/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:59:21 by steh              #+#    #+#             */
/*   Updated: 2022/12/19 16:34:59 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

void	get_texture(char *texture_path, t_texture *texture)
{
	if (texture->path != NULL)
		ft_exit2("Error\nMultiple identifiers found\n");
	texture_path = ft_strtrim(texture_path, " \t");
	texture->path = ft_strdup(texture_path);
	free(texture_path);
}

void	get_color(char *color_path, t_color *color)
{
	char			**color_split;
	unsigned int	i;

	i = 0;
	color_path = ft_strtrim(color_path, " \t");
	color_split = ft_split(color_path, ',');
	if (!ft_isdigit(color_path[ft_strlen(color_path) - 1]))
		ft_exit2("Error\nInvalid character at the end of color code");
	while (color_split[i] && is_str_digit(color_split[i]))
		i++;
	if (i == 3)
	{
		color->r = ft_atoi(color_split[0]);
		color->g = ft_atoi(color_split[1]);
		color->b = ft_atoi(color_split[2]);
	}
	else
		ft_exit2("Error\nInvalid color code");
	free_strs(color_split);
	free(color_split);
	free(color_path);
}

void	get_data(char **strs, t_scene *scene)
{
	if (strs[0] == 0)
		return ;
	else if (ft_strstr(strs[0], "NO") != NULL && strs[1] == NULL)
		get_texture(&strs[0][3], &scene->no_tex);
	else if (ft_strstr(strs[0], "SO") != NULL && strs[1] == NULL)
		get_texture(&strs[0][3], &scene->so_tex);
	else if (ft_strstr(strs[0], "WE") != NULL && strs[1] == NULL)
		get_texture(&strs[0][3], &scene->we_tex);
	else if (ft_strstr(strs[0], "EA") != NULL && strs[1] == NULL)
		get_texture(&strs[0][3], &scene->ea_tex);
	else if (ft_strstr(strs[0], "F") != NULL && strs[1] == NULL)
		get_color(&strs[0][2], &scene->floor_color);
	else if (ft_strstr(strs[0], "C") != NULL && strs[1] == NULL)
		get_color(&strs[0][2], &scene->ceiling_color);
	else if (ft_strstr(strs[0], "DO") != NULL && strs[1] == NULL)
		get_texture(&strs[0][3], &scene->do_tex);
	else
		ft_exit2("invalid identifier\n");
}
