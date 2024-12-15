/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:26:30 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/06 17:26:30 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

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
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	s_trimmed = malloc((end - start + 2) * sizeof(char));
	if (!s_trimmed)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		s_trimmed[i] = s1[start + i];
		i++;
	}
	s_trimmed[i] = '\0';
	return (s_trimmed);
}
