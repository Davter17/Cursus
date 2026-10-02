/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:14 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/28 22:22:26 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (ft_is_separator(str[i], charset))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_separator(str[i], charset))
		i++;
	return (i);
}

char	*ft_strdup_word(char *str, char *charset)
{
	char	*word;
	int		len;
	int		i;

	len = ft_word_len(str, charset);
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		words;

	words = ft_count_words(str, charset);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		while (str[i] && ft_is_separator(str[i], charset))
			i++;
		result[j] = ft_strdup_word(&str[i], charset);
		if (!result[j])
			return (NULL);
		i += ft_word_len(&str[i], charset);
		j++;
	}
	result[j] = NULL;
	return (result);
}

/*
int	main(int argc, char **argv)
{
	char	**matrix;

	if (argc == 3)
		matrix = ft_split(argv[1], argv[2]);
	return (0);
}
*/
