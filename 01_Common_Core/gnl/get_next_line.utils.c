/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:55:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/06 02:55:34 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (c == '\0' && s)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	if (s1)
		free(s1);
	return (new);
}

char	*ft_get_line(char *saved)
{
	char	*line;
	size_t	i;
	size_t	len;

	i = 0;
	while (saved && saved[i] && saved[i] != '\n')
		i++;
	if (saved && saved[i] == '\n')
		i = i + 1;
	len = i;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = saved[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *saved)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (saved && saved[i] && saved[i] != '\n')
		i++;
	if (saved == NULL || saved[i] == '\0')
		return (free(saved), NULL);
	i = i + 1;
	len = ft_strlen(saved + i);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	j = 0;
	while (saved[i + j])
	{
		new[j] = saved[i + j];
		j++;
	}
	new[j] = '\0';
	free(saved);
	return (new);
}
