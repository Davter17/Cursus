/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:52:04 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/06 17:52:04 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

// Allocates memory for each substring in the result array.

char	**ft_allocate_result(char **result, size_t s_word, size_t len)
{
	result[s_word] = malloc((len + 1) * sizeof(char));
	if (!result[s_word])
	{
		while (s_word > 0)
			free(result[--s_word]);
		free(result);
		return (NULL);
	}
	return (result);
}

// Splits the string into substrings up to `max_words` and allocates memory.

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
		while (s[i + j] != c && s[i + j] != '\0')
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

// Splits the string `s` into an array of substrings, separated by `c`.

char	**ft_split(char const *s, char c)
{
	size_t	max_words;
	size_t	i;
	char	**result;

	max_words = 0;
	i = 0;
	if (!s)
		return (NULL);
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
