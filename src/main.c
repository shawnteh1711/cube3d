/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:52:52 by steh              #+#    #+#             */
/*   Updated: 2022/10/05 19:38:42 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../inc/struct.h"
#include "../inc/cube3d.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	game;

	fd = 0;
	if (argc == 2)
	{
		fd = check_file(fd, argv);
		if (fd == -1)
			exit(EXIT_SUCCESS);
		get_file(fd, &game);
	}
	close(fd);
	// system("leaks program");
	return (0);
}
