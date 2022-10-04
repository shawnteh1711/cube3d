/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:52 by steh              #+#    #+#             */
/*   Updated: 2022/10/04 21:49:05 by steh             ###   ########.fr       */
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

int	check_map(t_map *map)
{
	size_t	i;
	int		j;

	i = 1;
	j = 0;
	printf("map->wodth: %d\n", map->width);
	while (j < map->height)
	{
		i = ft_strlen_cube3d(map->grid[j]);
		printf("%zu\n", i);
		j++;
		// if (map->grid[0][j] != '1'
		// 	&& map->grid[map->height - 1][j] != '\t')
		// {
		// 	printf("row 1 no close with wall\n");
		// 	return (0);
		// }
		// if (map->grid[map->height - 1][j] != '1'
		//   && map->grid[map->height - 1][j] != ' ')
		// {
		// 	printf("last row no close with wall\n");
		// 	return (0);
		// }
		// j++;
	}
	return (1);
}
