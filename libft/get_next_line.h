/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:18:34 by steh              #+#    #+#             */
/*   Updated: 2022/03/05 10:54:01 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// for free() and malloc()
# include <stdlib.h>

// for printf in main.c
# include <stdio.h>

// for read() and close()
# include <unistd.h>

// for O_RDONLY
# include <fcntl.h>

char		*get_next_line(int fd);
char		*ft_read_and_save(int fd, char *save_line);
char		*ft_get_line(char *save_line);
char		*ft_save_next_line(char *save_line);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dest, const char *src, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);

#endif