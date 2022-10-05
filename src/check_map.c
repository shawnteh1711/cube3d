/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:05:00 by steh              #+#    #+#             */
/*   Updated: 2022/10/05 22:42:05 by steh             ###   ########.fr       */
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
		{
			printf("row 1 not enclose with wall\n");
			// system("leaks program");
			exit(EXIT_SUCCESS) ;
		}
		i++;
	}
	i = 0;
	width = ft_strlen_cube3d(map->grid[map->height - 1]);
	while (i < width)
	{
		if (map->grid[map->height - 1][i] != '1'
			&& map->grid[map->height - 1][i] != ' ')
		{
			printf("last row not close with wall\n");
			// system("leaks program");
			exit(EXIT_SUCCESS) ;
		}
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
		{
			printf("mid index 1 not enclose with wall\n");
			// system("leaks program");
			exit(EXIT_SUCCESS) ;
		}
		else if (map->grid[i][0] == ' ')
		{
			j = 0;
			while (map->grid[i][j] == ' ')
				j++;
			if (map->grid[i][j] != '1')
			{
				printf("mid index not enclose with wall\n");
				// system("leaks program");
				exit(EXIT_SUCCESS) ;
			}
		}
		if (map->grid[i][width - 1] != '1' && map->grid[i][width - 1] != ' ')
		{
			printf("mid last index not enclose with wall\n");
			// system("leaks program");
			exit(EXIT_SUCCESS) ;
		}
		i++;
	}
}