/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:29:58 by steh              #+#    #+#             */
/*   Updated: 2022/10/01 20:17:29 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(const char *str, const char *delim)
{
	static char	*p;
	char		*ret;
	int			i;

	if (str)
		p = (char *)str;
	i = 0;
	while (p[i] && ft_strchr(delim, p[i]))
		i++;
	if (!*p)
		return (NULL);
	ret = p;
	p += i;
	if (*p)
	{
		i = 0;
		while (p[i] && !ft_strchr(delim, p[i]))
			i++;
		p[i] = '\0';
		p += i + 1;
	}
	return (ret);
}