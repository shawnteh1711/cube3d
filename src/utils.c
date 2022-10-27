/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:34 by steh              #+#    #+#             */
/*   Updated: 2022/10/26 20:58:56 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	is_map(char *line)
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("012NSEW \n\t\v\f\r", *line))
			return (0);
		else if (*line == '1')
			check = 1;
		line++;
	}
	return (check);
}

void	free_strs(char **strs)
{
	while (*strs)
		free(*strs++);
}

char	*ft_strdup2(const char *src, size_t col_num)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (col_num + 1));
	if (dest == NULL)
		return (NULL);
	if (col_num == 0)
		return (NULL);
	while (i < col_num)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	// printf("dest: [%s]\n", dest);
	return (dest);
}

int	is_str_digit(char *c)
{
	if (!c)
		return (0);
	while (*c)
	{
		if (!ft_isdigit((*c)))
		{
			printf("not digit\n");
			return (0);
		}
		c++;
	}
	return (1);
}
