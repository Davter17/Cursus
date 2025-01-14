/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:06 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 17:02:08 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// Removes characters from the beginning and end of s1 that are also in the set.

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s_trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start >= end)
		return (ft_calloc(1, sizeof(char)));
	end--;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	s_trimmed = malloc((end - start + 2) * sizeof(char));
	if (!s_trimmed)
		return (NULL);
	i = -1;
	while (start + ++i <= end)
		s_trimmed[i] = s1[start + i];
	s_trimmed[i] = '\0';
	return (s_trimmed);
}
