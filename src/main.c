/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:52:52 by steh              #+#    #+#             */
/*   Updated: 2022/10/27 19:47:44 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../inc/struct.h"
#include "../inc/cube3d.h"


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
	close(fd);
	// system("leaks program");
	return (0);
}
