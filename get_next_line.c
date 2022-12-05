/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:07:31 by naterrie          #+#    #+#             */
/*   Updated: 2022/12/05 20:15:21 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i])
		str = malloc(sizeof(char) * (i + 2));
	else
		str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (buf[++i] && buf[i] != '\n')
		str[i] = buf[i];
	if (buf[i] == '\n')
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_next_buf(char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		i++;
	}
	j = 0;
	if (!buf[i])
		return (free(buf), NULL);
	str = malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!str)
		return (free(buf), NULL);
	i++;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	return (free(buf), str);
}

char	*ft_read_line(int fd, char *buf)
{
	char	*temp;
	int		bytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (free(buf), buf = NULL, NULL);
	bytes = 1;
	while (!ft_strchr(buf, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buf), free(temp), NULL);
		temp[bytes] = '\0';
		buf = ft_strjoin(buf, temp);
	}
	return (free(temp), buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buf)
			free(buf);
		return (NULL);
	}
	buf = ft_read_line(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_next_buf(buf);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("read_error.txt", O_RDONLY);
	i = 1;
	while (i < 6)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

#include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (!c)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *buf, char *temp)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!buf)
	{
		buf = malloc(sizeof(char) * 1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	if (!temp)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(temp) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (buf[++i])
		str[i] = buf[i];
	while (temp[j] != '\0')
		str[i++] = temp[j++];
	str[ft_strlen(buf) + ft_strlen(temp)] = '\0';
	free(buf);
	return (str);
}*/
