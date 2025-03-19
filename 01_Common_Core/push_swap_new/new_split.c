/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:51 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/17 18:53:28 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static int count_words(char *s)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while(s[i])
	{
		if (i == 0 && s[i] != ' ')
			words++;
		else if (s[i] != ' ' && s[i - 1] == ' ')
			words++;
		i++;
	}
	return (words);
}

static char *get_next_word(char *s)
{
	static int	actual;
	char		*word;
	int			len;

	len = 0;
	while(s[actual] == ' ')
		actual++;
	while(s[actual + len] && s[actual + len] != ' ')
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[actual], len + 1);
	actual += len;
	return (word);
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result;
	int		i;

	i = 0;

	words_count
}

int main(void)
{
	char	*str;

	str = "        hello         world     ";
	printf("%s\n", get_next_word(str));
	printf("%s", get_next_word(str));
}
*/