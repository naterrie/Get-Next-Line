/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:07:31 by naterrie          #+#    #+#             */
/*   Updated: 2022/11/30 19:25:10 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buf)
{
	int		byte_read;
	char	*res;

	printf("ici c'est bon(readfile)\n");
	if (!buf)
	{
		buf = ft_calloc(sizeof(char), 1);
		buf[1] = 0;
	}
	res = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, res, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(res);
			return (NULL);
		}
		res[byte_read] = 0;
		if (ft_strchr(res, '\n'))
			break ;
	}
	free(res);
	return (buf);
}

char	*ft_buf(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	line = ft_calloc(sizeof(char), (ft_strlen(buf) - i + 1));
	i++;
	j = 0;
	while (buf[i])
		line[j++] = buf[i++];
	free(buf);
	return (line);
}

char	*ft_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) <= 0 || \
		read(fd, buf, BUFFER_SIZE) == -1)
		return (NULL);
	buf = read_file(fd, buf);
	printf("ici c'est bon(read_files_end)\n");
	line = ft_line(buf);
	buf = ft_buf(buf);
	return (line);
}
