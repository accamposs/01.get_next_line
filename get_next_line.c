/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:48:59 by catperei          #+#    #+#             */
/*   Updated: 2021/06/30 14:42:58 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	saveline(int fd, char **line, char **s)
{
	int			len;
	char		*tmp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len])
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_substr(s[fd], 0, len);
		tmp = ft_substr(s[fd], len + 1, ft_strlen(s[fd]) - len);
		free(s[fd]);
		s[fd] = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = 0;
		return (0);
	}
}

static int	output(int fd, char **line, char **s, int reader)
{
	if (reader < 0)
		return (-1);
	if (!reader && s[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (saveline(fd, line, s));
}

int	get_next_line(int fd, char **line)
{
	static char	*s[FD_SETSIZE];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			reader;

	if (fd < 0 || !line || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (-1);
	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		buff[reader] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup("");
		tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(fd, line, s, reader));
}
