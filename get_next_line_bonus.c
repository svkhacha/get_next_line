/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:06:00 by svkhacha          #+#    #+#             */
/*   Updated: 2022/04/13 22:36:20 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check(long *readsize, char **buff, int fd, char *line)
{
	char	*tmp;
	char	*static_line;

	static_line = line;
	*readsize = read(fd, *buff, BUFFER_SIZE);
	(*buff)[*readsize] = '\0';
	if (*readsize == -1)
		return (0);
	if (!static_line)
		static_line = ft_strdup(*buff);
	else
	{
		tmp = static_line;
		static_line = ft_strjoin(static_line, *buff);
		free(tmp);
	}
	return (static_line);
}

char	*static_line_func(int fd, long readsize, char *static_line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*b;

	b = buff;
	while (1)
	{
		static_line = check(&readsize, &b, fd, static_line);
		if (!static_line)
			return (0);
		if (ft_strchr(buff, '\n') || readsize == 0)
			break ;
	}
	if (readsize == 0 && !*static_line)
	{
		free(static_line);
		return (0);
	}
	return (static_line);
}

char	*get_next_line(int fd)
{
	long		i;
	long		readsize;
	static char	*sline[OPEN_MAX];
	char		*line;
	char		*temp;

	readsize = 1;
	if (readsize == 0)
		return (NULL);
	sline[fd] = static_line_func(fd, readsize, sline[fd]);
	i = ft_strlen(sline[fd]) - ft_strlen(ft_strchr(sline[fd], '\n')) + 1;
	line = ft_substr(sline[fd], 0, i);
	temp = sline[fd];
	sline[fd] = ft_substr(sline[fd], i, ft_strlen(sline[fd]));
	free(temp);
	return (line);
}
