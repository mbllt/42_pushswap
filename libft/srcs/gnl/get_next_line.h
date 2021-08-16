/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:01:40 by mballet           #+#    #+#             */
/*   Updated: 2021/01/13 16:09:37 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		condition_fill_in_temp(char **temp);
int		fill_in_temp(char **temp, char *buffer);
int		fill_in_line(char **temp, ssize_t buf_size, char **line);
int		reset_temp(char **temp, int read_return);
int		line_null(char **line);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
ssize_t	free_temp(char **temp, ssize_t read_return);

#endif
