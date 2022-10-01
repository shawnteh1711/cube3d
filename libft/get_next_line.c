/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:17:30 by steh              #+#    #+#             */
/*   Updated: 2022/10/01 23:05:27 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t read(int fd, void *buf, size_t count);
// if read count is zero(BUFFER SIZE), read may return error
// keep reading while the char *save not find '\n' using strchr

char	*ft_read_and_save(int fd, char *save_line)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(save_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save_line = ft_strjoin(save_line, buffer);
	}
	free(buffer);
	return (save_line);
}

char	*ft_get_line(char *save_line)
{
	int		i;
	char	*s;

	i = 0;
	if (!save_line[i])
		return (NULL);
	while (save_line[i] && save_line[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	ft_strlcpy(s, save_line, i + 1);
	if (save_line[i] == '\n')
		s[i] = save_line[i];
	s[++i] = '\0';
	return (s);
}

char	*ft_save_next_line(char *save_line)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (save_line[i] && save_line[i] != '\n')
		i++;
	if (!save_line[i])
	{
		free(save_line);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen_gnl(save_line) - i + 1);
	if (!s)
		return (NULL);
	i++;
	while (save_line[i])
		s[j++] = save_line[i++];
	s[j] = '\0';
	free(save_line);
	return (s);
}

// read the text file pointed by fd, one line at a time
// return NULL if there is nothing to read or an error occured
char	*get_next_line(int fd)
{
	char		*line;
	static char	*save_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save_line = ft_read_and_save(fd, save_line);
	if (!save_line)
		return (NULL);
	line = ft_get_line(save_line);
	save_line = ft_save_next_line(save_line);
	return (line);
}
