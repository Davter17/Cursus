/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:53 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/04 23:19:29 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	len1 = -1;
	while (s1[++len1])
		new_str[len1] = s1[len1];
	len2 = -1;
	while (s2[++len2])
		new_str[len1 + len2] = s2[len2];
	new_str[len1 + len2] = '\0';
	return (new_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	len = -1;
	while (s[++len])
		dup[len] = s[len];
	dup[len] = '\0';
	return (dup);
}
