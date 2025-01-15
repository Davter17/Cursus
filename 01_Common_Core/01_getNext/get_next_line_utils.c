/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:53 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 01:59:56 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while(s[i])
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[i] = '\0';
	while(i > 0)
	{
		i--;
		dup[i] = s[i];
	}
	return(dup);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;
	
	i = 0;
	while(s[i] && i < n)
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[i] = '\0';
	while(i > 0)
	{
		i--;
		dup[i] = s[i];
	}
	return(dup);
}