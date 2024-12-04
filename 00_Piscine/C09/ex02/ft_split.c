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

#include <unistd.h>

int	count_splits(char *str, char *charset)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 1;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				counter++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (counter);
}

int	*calculate_len(char *str, char *charset, int splits, char **matrix)
{
	int	i;
	int	j;
	int	*size_splits;
	int	size_split_position;
	int	size_split_counter;

	i = 0;
	size_split_position = 0;
	size_split_counter = 0;
	size_splits = malloc(splits * sizeof(int));
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				if (size_split_counter > 0)
					size_splits[size_split_position++] = size_split_counter;
				size_split_counter = 0;
			}
			j++;
		}
		size_split_counter++;
		i++;
	}
	if (size_split_counter > 0)
		size_splits[size_split_position] = size_split_counter;
	return (size_splits);
}

char	**ft_allocate_split(char *str, char *charset)
{
	char	**matrix;
	int		splits;
	int		i;
	int		*len_to_splits;

	splits = count_splits(str, charset);
	matrix = malloc((splits + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	len_to_splits = calculate_len(str, charset, splits, matrix);
	if (!len_to_splits)
		return (NULL);
	i = 0;
	while (i < splits)
	{
		matrix[i] = malloc(len_to_splits[i] * sizeof(char));
		if (!matrix[i])
			return (NULL);
		i++;
	}
	matrix[splits] = NULL;
	free(len_to_splits);
	return (matrix);
}

char	**ft_split(char *str, char *charset)
{
	char	**matrix;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	matrix = ft_allocate_split(str, charset);
	if (!matrix)
		return (NULL);
	while (str[i])
	{
		k = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				j++;
				k = 0;
			}
			else
			{
				matrix[j][k] = str[i];
				k++;
			}
			i++;
		}
	}
	matrix[j] = NULL;
	return (matrix);
}

int	main(int argc, char **argv)
{
	char	**matrix;

	if (argc == 3)
		matrix = ft_split(argv[1], argv[2]);
	return (0);
}
