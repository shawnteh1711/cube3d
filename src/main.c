// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/05/31 12:05:32 by steh              #+#    #+#             */
// /*   Updated: 2022/09/26 16:26:00 by steh             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../inc/cube3d.h"


void	get_texture(char *texture_path, t_texture *texture)
{
	texture_path = ft_strtrim(texture_path, " \t");
	texture->path = ft_strdup(texture_path);
	free(texture_path);
}

int	is_str_digit(char *c)
{
	if (!c)
		return (0);
	while (*c)
	{
		if (!ft_isdigit((*c)))
		{
			printf("not digit\n");
			return (0);
		}
		c++;
	}
	return (1);
}

void	free_strs(char **strs)
{
	while (*strs)
		free(*strs++);
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
	{
		get_texture(&strs[0][3], &scene->no_tex);
	}
	else if (ft_strstr(strs[0], "SO") != NULL && strs[1] == NULL)
	{
		get_texture(&strs[0][3], &scene->so_tex);
	}
	else if (ft_strstr(strs[0], "WE") != NULL && strs[1] == NULL)
	{
		get_texture(&strs[0][3], &scene->we_tex);
	}
	else if (ft_strstr(strs[0], "EA") != NULL && strs[1] == NULL)
	{
		get_texture(&strs[0][3], &scene->ea_tex);
	}
	else if (ft_strstr(strs[0], "F") != NULL && strs[1] == NULL)
	{
		get_color(&strs[0][2], &scene->floor_color);
	}
	else if (ft_strstr(strs[0], "C") != NULL && strs[1] == NULL)
	{
		get_color(&strs[0][2], &scene->ceiling_color);
	}
	// else
	// {
	// 	printf("strs[0]: %s\n", strs[0]);
	// 	printf("strs[0][1]: %c\n", strs[0][1]);
	// 	printf("strs[1]: %s\n", strs[1]);
	// }
}

int		is_map(char *line)
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("012NSEW \n\t\v\f\r", *line))
			return (0);
		else if (*line == '1')
			check = 1;
		line++;
	}
	return (check);
}

void	extract_dimension(t_map *map)
{
	int		width;
	int		i;

	map->height = 0;
	map->width = 0;
	i = 0;
	width = 0;
	while (map->grid[i] != NULL)
	{
		width = ft_strlen_cube3d(map->grid[i]);
		if (width >= map->width)
			map->width = width;
		map->height++;
		i++;
	}
	// printf("width: %d\n", map->width);
	// printf("height: %d\n", map->height);
}

char	*ft_strdup2(const char *src, size_t col_num)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (col_num + 1));
	if (dest == NULL)
		return (NULL);
	if (col_num == 0)
		return (NULL);
	while (i < col_num)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char**	copy_map(int fd, char *line)
{
	size_t	i;
	size_t	n;
	char	**arr;
	
	i = 0;
	arr = (char **)malloc(sizeof(char *));
	while (1)
	{
		arr = ft_realloc(arr, (i + 1) * sizeof(char *), (i + 2) * sizeof(char *));
		n = ft_strlen_cube3d(line);
		arr[i++] = ft_strdup2(line, n);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	arr[i] = NULL;
	// free_strs(arr);
	// free(arr);
	return (arr);
}

// get the map information.
void	get_map(int fd, char *line, t_map *map)
{
	int	i;
	int	len;
	char	cpy[10];

	i = 0;
	while (line[i])
	{

		len = ft_strlen(line);
		if (line[i] == '\t')
		{
			printf("i:%d\n", i);
			printf("len:%d\n", len);
			ft_memmove(cpy, &line[i], 9);
			// ft_strlcpy(&line[i], "    ", 4);
			// printf("%s", line);
			printf("%s", cpy);
			len += 4;
		}
		i++;
	}
	map->grid = copy_map(fd, line);
	extract_dimension(map);
	// free_strs(map->grid);
	// free(map->grid);
}


int main(int argc, char const *argv[])
{
	int		fd;
	int		len;
	char	*ext;
	t_game	game;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			printf("file not exit\n");
			return (0);
		}
		len = ft_strlen(argv[1]);
		ext = (char *)ft_memchr(argv[1], '.', len);
		if (!ft_strcmp(ext, ".cub"))
			printf("file is cub\n");
		else
			printf("file is not cub\n");

			
		char	*line;
		char	**strs;

		line = get_next_line(fd);
		while (line != NULL)
		{
			if (is_map(line))
				get_map(fd, line, &game.map);
			if (!is_map(line))
			{
				strs = ft_split(line, '\n');
				get_data(strs, &game.scene);
				free_strs(strs);
				free(strs);
			}		
			free(line);
			line = get_next_line(fd);
		}
		// printf("no: %s\n", game.scene.no_tex.path);
		// printf("so: %s\n", game.scene.so_tex.path);
		// printf("we: %s\n", game.scene.we_tex.path);
		// printf("ea: %s\n", game.scene.ea_tex.path);
		// printf("fr: %i\n", game.scene.floor_color.r);
		// printf("fg: %i\n", game.scene.floor_color.g);
		// printf("fb: %i\n", game.scene.floor_color.b);
		// printf("cr: %i\n", game.scene.ceiling_color.r);
		// printf("cg: %i\n", game.scene.ceiling_color.g);
		// printf("cb: %i\n", game.scene.ceiling_color.b);
		// printf("\n\n");
		free(line);
		close(fd);
		// system("leaks program");
	}
	return (0);
}
