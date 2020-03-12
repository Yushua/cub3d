/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 10:54:48 by ybakker        #+#    #+#                */
/*   Updated: 2020/03/05 10:55:24 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#	ifndef __GET_NEXT_LINE_H
#	define __GET_NEXT_LINE_H
#	include <unistd.h>
#	include <fcntl.h>
#	include <stdlib.h>
#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 100
#	endif

int				get_next_line(const int fd, char **line);
size_t			ft_strlen_gnl(const char *s);
char			*ft_strchr_gnl(const char *s, int c);
char			*ft_strdup_gnl(const char *s1);
char			*ft_strjoin_gnl(char const *s1, char const *s2);
char			*ft_strsub_gnl(char *str, int start, int len);

#	endif