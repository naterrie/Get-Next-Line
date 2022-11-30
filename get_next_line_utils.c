/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:07:30 by naterrie          #+#    #+#             */
/*   Updated: 2022/11/30 19:18:27 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	printf("ici c'est bon(strlen)\n");
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	printf("ici c'est bon(calloc)\n");
	str = malloc(sizeof(char) * (size * count));
	if (!str)
		return (NULL);
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	printf("ici c'est bon(strchr)\n");
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == '\0')
		return ((char *)(s + i));
	return (NULL);
}
