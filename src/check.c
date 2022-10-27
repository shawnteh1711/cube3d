/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:52 by steh              #+#    #+#             */
/*   Updated: 2022/10/27 19:06:18 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

int	check_file(char **argv)
{
	int fd;

	fd = check_file_exits(argv[1]);
	if (fd == -1)
		return (-1);
	if (!check_file_extension(argv[1], ".cub"))
		return (-1);
	return (fd);
}

void	check_tab(char *line)
{
	int i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			printf("map cannot contain tab\n");
			free(line);
			// system("leaks program");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

void	check_newline(char *line)
{
	int i;
	
	i = 0;
	while (line[i])
	{
		if (line[0] == '\n')
		{
			printf("map cannot contain empty line\n");
			free(line);
			system("leaks program");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

// printf("map->grid[%d][%d]: %c\n", i, j, map->grid[i][j]);
void	check_map(t_map *map)
{
	check_first_last_row(map);
	check_middle_row(map);
	check_unwanted_char(map);
}

int		check_map_enclosed(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] != '1' && map->grid[i][j] != ' ')
			{
				if (i == 0 || j == 0 || i == map->height - 1 || j == map->width - 1)
					return (0);
				else if (map->grid[i - 1][j - 1] == ' ' || map->grid[i - 1][j] == ' '
					|| map->grid[i - 1][j + 1] == ' ' || map->grid[i][j + 1] == ' '
					|| map->grid[i + 1][j + 1] == ' ' || map->grid[i + 1][j] == ' '
					|| map->grid[i + 1][j - 1] == ' ' || map->grid[i][j - 1] == ' ')
					{
						printf("grid[%d][%d]: %c\n", i, j, map->grid[i][j]);
						return (0);
					}
			}
		}
	}
	return (1);
}
