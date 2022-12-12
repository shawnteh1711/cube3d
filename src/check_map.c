/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:05:00 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 16:52:56 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

void	check_first_last_row(t_map *map)
{
	int		i;
	int		width;

	i = 0;
	width = ft_strlen_cube3d(map->grid[0]);
	while (i < width)
	{
		if (map->grid[0][i] != '1' && map->grid[0][i] != ' ')
			ft_exit("row 1 not enclose with wall", map);
		i++;
	}
	i = 0;
	width = ft_strlen_cube3d(map->grid[map->height - 1]);
	while (i < width)
	{
		if (map->grid[map->height - 1][i] != '1'
			&& map->grid[map->height - 1][i] != ' ')
			ft_exit("last row not close with wall", map);
		i++ ;
	}
}

void	check_middle_row(t_map *map)
{
	int	i;
	int	j;
	int	width;

	i = 1;
	while (i < map->height - 1)
	{
		width = ft_strlen_cube3d(map->grid[i]);
		if (map->grid[i][0] != '1' && map->grid[i][0] != ' ')
			ft_exit("mid index 1 not enclose with wall", map);
		else if (map->grid[i][0] == ' ')
		{
			j = 0;
			while (map->grid[i][j] == ' ')
				j++;
			if (map->grid[i][j] != '1')
				ft_exit("mid index not enclose with wall", map);
		}
		if (map->grid[i][width - 1] != '1' && map->grid[i][width - 1] != ' ')
			ft_exit("mid last index not enclose with wall", map);
		i++;
	}
}

void	check_unwanted_char(t_map *map)
{
	int	i;
	int	j;
	int	width;

	i = -1;
	width = 0;
	map->position = 0;
	while (++i < map->height)
	{
		width = ft_strlen_cube3d(map->grid[i]);
		j = -1;
		while (++j < width)
		{
			if (!ft_strchr("01NSEW ", map->grid[i][j]))
			{
				printf("map->grid[%d][%d]: %c\n", i, j, map->grid[i][j]);
				ft_exit("map contains invalid character", map);
			}
			if (ft_strchr("NSEW", map->grid[i][j]))
				map->position += 1;
		}
	}
	if (map->position != 1)
		ft_exit("map error starting position", map);
}
