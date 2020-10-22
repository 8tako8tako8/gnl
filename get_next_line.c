/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:56:16 by kmorimot          #+#    #+#             */
/*   Updated: 2020/10/22 21:50:06 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read_error(char **line, char **save, int fd)
{
	free(*line);
	free(save[fd]);
	return (-1);
}

int		ft_find_line(char **line, char **save, int fd, char *buf)
{
	size_t		find_line;
	int			flag;
	char		*tmp1;
	char		*tmp2;

	flag = 0;
	tmp2 = NULL;
	find_line = ft_strchr2(buf, '\n');
	if (!(tmp1 = ft_strjoin2(*line, buf, find_line)))
		return (-1);
	free(*line);
	*line = tmp1;
	if (buf[find_line] == '\n')
	{
		if (!(tmp2 = ft_strdup(buf + find_line + 1)))
			return (-1);
		flag = 1;
	}
	free(save[fd]);
	save[fd] = tmp2;
	return (flag);
}

int		get_next_line(int fd, char **line)
{
	static char		*save[MAX_FD];
	char			*buf;
	ssize_t			r_size;
	int				flag;

	flag = 0;
	if (fd < 0 || MAX_FD <= fd || line == NULL)
		return (-1);
	if (!(*line = (char *)malloc(1)))
		return (-1);
	*line[0] = '\0';
	if (save[fd] != NULL)
		flag = ft_find_line(line, save, fd, save[fd]);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
    while (flag == 0 && fd == 0 && (r_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r_size] = '\0';
		flag = ft_find_line(line, save, fd, buf);
	}
	while (flag == 0 && fd > 0 && (r_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r_size] = '\0';
		flag = ft_find_line(line, save, fd, buf);
	}
	free(buf);
	if (r_size == -1)
		return (ft_read_error(line, save, fd));
	return (flag);
}
