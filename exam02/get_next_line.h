/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:16:36 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/13 00:42:20 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
//# define BUFFER_SIZE 1024

int			get_next_line(int fd, char **line);
int			ft_find_line(char **line, char **save, char *buf);
int			ft_stdin_or_read_file(char **line, char **save, int fd);
int			ft_read_error(char **line, char **save);
size_t		ft_strlen(char *s);
char		*ft_strdup(const char *s1);
void		ft_strlcpy2(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin2(char const *s1, char const *s2, size_t len2);
size_t		ft_strchr2(const char *s, char c);

#endif
