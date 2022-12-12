/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:18:02 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 16:59:09 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

// if last line is empty, still acceptable as it return NULL and break.
// if contain more than 2 empty line at bottom is not acceptable 
// and throw error.
// line: 36 free . uncomment to avoid leak. Comment now because fsanitize issue
char	**copy_map(int fd, char *line)
{
	size_t	i;
	size_t	n;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *));
	if (!arr)
		exit(EXIT_SUCCESS);
	while (1)
	{
		arr = ft_realloc(arr, (i + 1) * sizeof(char *),
				(i + 2) * sizeof(char *));
		check_tab(line);
		check_newline(line);
		n = ft_strlen_cube3d(line);
		arr[i++] = ft_strdup2(line, n);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	arr[i] = NULL;
	return (arr);
}

void	ft_realloc_protected(void **ptr, size_t orig_size, size_t new_size)
{
	*ptr = ft_realloc(*ptr, orig_size, new_size);
	if (*ptr == 0)
		exit(EXIT_SUCCESS);
}

void	add_padding(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	while (++i < (size_t)map->height)
	{
		j = -1;
		len = ft_strlen_cube3d(map->grid[i]);
		if (len < (size_t)map->width)
			ft_realloc_protected((void **)&map->grid[i],
				len + 1, map->width + 1);
		while (++j < (size_t)map->width)
		{
			if (j >= len)
				map->grid[i][j] = ' ';
		}
		map->grid[i][j] = '\0';
	}
}

// get the map information.
void	get_map(int fd, char *line, t_map *map)
{
	map->grid = copy_map(fd, line);
	extract_dimension(map);
	add_padding(map);
	check_unwanted_char(map);
}
