/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:53 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/24 11:46:39 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i] && i < n)
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[i] = '\0';
	while (i > 0)
	{
		i--;
		dup[i] = s[i];
	}
	return (dup);
}
