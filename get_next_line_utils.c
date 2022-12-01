/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:07:30 by naterrie          #+#    #+#             */
/*   Updated: 2022/12/01 16:56:58 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (!c)
		return (ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = malloc(sizeof(char) * 1);
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	if (!buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(left_str) + ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (left_str[++i])
		str[i] = left_str[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(left_str) + ft_strlen(buf)] = '\0';
	free(left_str);
	return (str);
}
