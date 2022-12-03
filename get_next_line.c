/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:07:31 by naterrie          #+#    #+#             */
/*   Updated: 2022/12/03 17:06:14 by naterrie         ###   ########lyon.fr   */
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
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
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
		i++;
	j = 0;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buf) - i) + 1);
	if (!str)
		return (NULL);
	i++;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	free(buf);
	return (str);
}

char	*ft_read_line(int fd, char *buf)
{
	char	*temp;
	int		bytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buf, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(buf);
			return (NULL);
		}
		temp[bytes] = '\0';
		buf = ft_strjoin(buf, temp);
	}
	free(temp);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_read_line(fd, buf); // Lit jusqu'a trouver un \n ou que read renvois 0
	if (!buf)
		return (NULL);
	line = ft_get_line(buf); // Recuperer tout ce qui est avant le \n (donc la ligne)
	buf = ft_next_buf(buf); // Set tout ce que est lu apres le \n dans la static
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
	while (i < 3)
	{
		line = get_next_line(fd);
		fd = 6;
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
#  define BUFFER_SIZE 1
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
