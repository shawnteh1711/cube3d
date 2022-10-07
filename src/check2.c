/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:02:14 by steh              #+#    #+#             */
/*   Updated: 2022/10/07 22:03:14 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"
#include "../inc/struct.h"

int	check_file_extension(char *filename, char *ck_ext)
{
	size_t	len;
	size_t	extlen;

	len = ft_strlen(filename);
	extlen = ft_strlen(ck_ext);
	if (len < extlen)
		return (-1);
	filename += (len - extlen);
	if (!ft_strcmp(filename, ck_ext))
		printf("file is %s\n", ck_ext);
	else
	{
		printf("file is not %s\n", ck_ext);
		return (-1);
	}
	return (1);
}

int	check_file_exits(char *filename)
{
	int	fd;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		printf("%s not exit\n", filename);
		return (-1);
	}
	return (fd);
}
