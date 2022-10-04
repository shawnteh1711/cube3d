/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:18:02 by steh              #+#    #+#             */
/*   Updated: 2022/10/04 21:51:19 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

char	**copy_map(int fd, char *line)
{
	size_t	i;
	size_t	n;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *));
	while (1)
	{
		arr = ft_realloc(arr, (i + 1) * sizeof(char *),
				(i + 2) * sizeof(char *));
		n = ft_strlen_cube3d(line);
		arr[i++] = ft_strdup2(line, n);
		// free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	arr[i] = NULL;
	// free_strs(arr);
	// free(arr);
	return (arr);
}

void	ft_realloc_protected(void **ptr, size_t orig_size, size_t new_size)
{
	*ptr = ft_realloc(*ptr, orig_size, new_size);
	if (*ptr == 0)
		exit(EXIT_SUCCESS);
}

// get the map information.
void	get_map(int fd, char *line, t_map *map)
{
	int	i;
	int	j;
	int	len;

	map->grid = copy_map(fd, line);
	extract_dimension(map);

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		len = ft_strlen(map->grid[i]);
		if (len < map->width)
			ft_realloc_protected((void **)&map->grid[i], len + 1, map->width + 1);
		while (++j < map->width)
		// while (++j < len)
		{
			if (map->grid[i][j] == '\t')
			{
				// ft_memove(dest, src, bytetocopy);
				ft_memmove(&map->grid[i][j + 4], &map->grid[i][j + 1], len - j + 2);
				ft_strlcpy(&map->grid[i][j], "    ", 4);
				printf("found tab at %d index %d\n", i, j);
				len += 4;
			}
			else if (j >= len)
				map->grid[i][j] = ' ';
		}
		map->grid[i][j] = '\0';
	}
	// check_map(map);
	for (int i = 0; i < map->height; i++)
	{
		printf("%s\n", map->grid[i]);
		len = (int)ft_strlen_cube3d(map->grid[i]);
		printf("%d\n", len);

	}
	// free_strs(map->grid);
	// free(map->grid);
}

void	get_texture(char *texture_path, t_texture *texture)
{
	texture_path = ft_strtrim(texture_path, " \t");
	texture->path = ft_strdup(texture_path);
	// printf("texture path: %s\n", texture->path);
	free(texture_path);
}

void	get_color(char *color_path, t_color *color)
{
	char			**color_split;
	unsigned int	i;

	i = 0;
	color_path = ft_strtrim(color_path, " \t");
	color_split = ft_split(color_path, ',');
	while (color_split[i] && is_str_digit(color_split[i]))
		i++;
	if (i == 3)
	{
		color->r = ft_atoi(color_split[0]);
		color->g = ft_atoi(color_split[1]);
		color->b = ft_atoi(color_split[2]);
	}
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
	// else
	// {
	// 	printf("strs[0]: %s\n", strs[0]);
	// 	printf("strs[0][1]: %c\n", strs[0][1]);
	// 	printf("strs[1]: %s\n", strs[1]);
	// }
}
