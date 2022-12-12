/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:52:52 by steh              #+#    #+#             */
/*   Updated: 2022/12/12 13:23:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief Main function to check argv, parse map and init game
 * @param argc check number of argc is equal to 2 to run program
 * @param argv check path of map whether is in correct format or valid file
 * @return int return 0 if successfully finish the program else EXIT(SUCCESS);
 */

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;

	fd = 0;
	if (argc == 2)
	{
		init(&game);
		fd = check_file(argv);
		if (fd == -1)
			exit(EXIT_SUCCESS);
		get_file(fd, &game);
		ck_info(&game);
		init_game(&game);
	}
	if (argc == 1 || argc > 2)
	{
		printf("Error\nPlease enter ./program map/map.cub\n");
		exit(EXIT_SUCCESS);
	}
	close(fd);
	return (0);
}
