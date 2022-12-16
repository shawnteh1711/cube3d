/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:19:02 by steh              #+#    #+#             */
/*   Updated: 2022/12/16 22:11:21 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_exit(char *s, t_map *map)
{
	(void)map;
	printf("%s\n", s);
	free_strs(map->grid);
	free(map->grid);
	// system("leaks cub3D");
	exit(EXIT_SUCCESS);
}

void	ft_exit2(char *s)
{
	printf("%s\n", s);
	// system("leaks cub3D");
	exit(EXIT_SUCCESS);
}