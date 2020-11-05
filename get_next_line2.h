/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:16:36 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/05 19:52:37 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define MAX_FD 256
//# define BUFFER_SIZE 10

int		get_next_line(int fd, char **line);
int		ft_find_line(char **line, char **save, int fd, char *buf);
int		ft_read_error(char **line, char **save, int fd);
int		ft_stdin_find_line(char **line, char **save, int fd, char *buf, ssize_t read_size);
int		ft_read_file_find_line(char **line, char **save, int fd, char *buf, ssize_t read_size);
size_t	ft_strlen(char *s);
char	*ft_strdup(const char *s1);
void	ft_strlcpy2(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin2(char const *s1, char const *s2, size_t len2);
size_t	ft_strchr2(const char *s, char c);

#endif
