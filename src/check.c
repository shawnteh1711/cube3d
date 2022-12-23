/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:52 by steh              #+#    #+#             */
/*   Updated: 2022/12/22 15:19:32 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

int	check_file(char **argv)
{
	int	fd;

	fd = check_file_exits(argv[1]);
	if (fd == -1)
		return (-1);
	if (!check_file_extension(argv[1], ".cub"))
		return (-1);
	return (fd);
}

void	check_tab(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			printf("map cannot contain tab\n");
			free(line);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

void	check_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			printf("Error.\n Map cannot contain empty line\n");
			free(line);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

void	check_map(t_map *map)
{
	// check_first_last_row(map);
	// check_middle_row(map);
	check_unwanted_char(map, -1, -1);
}

int	check_map_enclosed(t_map *map, char **grid)
{
	int	i;
	int	j;

	i = -1;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (grid[i][j] != '1' && grid[i][j] != ' ')
			{
				if (i == 0 || j == 0
					|| i == map->height - 1 || j == map->width - 1)
					return (0);
				else if (grid[i - 1][j - 1] == ' ' || grid[i - 1][j] == ' '
					|| grid[i - 1][j + 1] == ' ' || grid[i][j + 1] == ' '
					|| grid[i + 1][j + 1] == ' ' || grid[i + 1][j] == ' '
					|| grid[i + 1][j - 1] == ' ' || grid[i][j - 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}
