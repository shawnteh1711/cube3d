/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:19:02 by steh              #+#    #+#             */
/*   Updated: 2022/10/10 08:38:56 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_exit(char *s, t_map *map)
{
	(void)map;
	printf("%s\n", s);
	// free_strs(map->grid);
	// free(map->grid);
	// system("leaks program");
	exit(EXIT_SUCCESS);
}