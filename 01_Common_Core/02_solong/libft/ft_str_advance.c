/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:48 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 17:02:50 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_allocate_result(char **result, size_t s_word, size_t len)
{
	result[s_word] = malloc((len + 1) * sizeof(char));
	if (!result[s_word])
	{
		while (s_word > 0)
		{
			s_word--;
			free(result[s_word]);
		}
		free(result);
		return (NULL);
	}
	return (result);
}

char	**ft_split_parse(size_t max_words, char **result, char const *s, char c)
{
	size_t	s_word;
	size_t	i;
	size_t	j;

	s_word = -1;
	i = 0;
	while (++s_word < max_words)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (!(ft_allocate_result(result, s_word, j)))
			return (NULL);
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
		{
			result[s_word][j] = s[i + j];
			j++;
		}
		result[s_word][j] = '\0';
		i += j;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	max_words;
	size_t	i;
	char	**result;

	if (!s)
		return (NULL);
	max_words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			max_words++;
		i++;
	}
	result = malloc((max_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_split_parse(max_words, result, s, c);
	if (!result)
		return (NULL);
	result[max_words] = NULL;
	return (result);
}

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

// Extracts a substring starting at `start` from the string `s`.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > (s_len - start))
		len = s_len - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	while (i < len && (start + i) < s_len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
