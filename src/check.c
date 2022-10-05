/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:52 by steh              #+#    #+#             */
/*   Updated: 2022/10/05 22:41:01 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

int	check_file(int fd, char **argv)
{
	int		len;
	char	*ext;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		printf("file not exit\n");
		return (-1);
	}
	len = ft_strlen(argv[1]);
	ext = (char *)ft_memchr(argv[1], '.', len);
	if (!ft_strcmp(ext, ".cub"))
	{
		printf("file is cub\n");
		return (fd);
	}
	else
	{
		printf("file is not cub\n");
		return (-1);
	}
	return (1);
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
}
