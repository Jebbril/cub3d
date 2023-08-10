/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:08:27 by orakib            #+#    #+#             */
/*   Updated: 2023/08/10 17:08:28 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
size_t	ft_strlen2(const char *s);
int		ft_strchr2(char *s);
char	*ft_strjoin2(char *s1, char *s2);
char	*readtoleft(char *leftover, int fd);
char	*get_1line(char *leftover);
char	*fix_left(char *leftover);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif