/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:06:45 by steh              #+#    #+#             */
/*   Updated: 2022/10/03 23:16:48 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		len;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy_gnl(new, s1, len);
	ft_strlcpy_gnl(new + ft_strlen_gnl(s1), s2, ft_strlen_gnl(s2) + 1);
	free(s1);
	return (new);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (len > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (len - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}

size_t	ft_strlcat_gnl(char *dest, char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen_gnl(dest);
	j = 0;
	if (len <= ft_strlen_gnl(dest))
		return (ft_strlen_gnl(src) + len);
	while (src[j] && i + 1 < len)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i + ft_strlen_gnl(&src[j]));
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	c;
// 	char	*str;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = '\0';
// 	}
// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	c = 0;
// 	if (s1)
// 		while (s1[++i] != '\0')
// 			str[i] = s1[i];
// 	while (s2[c] != '\0')
// 		str[i++] = s2[c++];
// 	str[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
// 	free(s1);
// 	return (str);
// }