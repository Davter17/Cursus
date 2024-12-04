/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:05:59 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/27 16:57:58 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define MAP_SIZE 2048

char	**allocate_matrix(int *matrix_size)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = malloc((matrix_size[0] + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (i < matrix_size[0])
	{
		matrix[i] = malloc(matrix_size[1] + 1);
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

int	process_map_to_matrix(char *map, char **matrix)
{
	int	indices[3];
	int	counter;

	indices[0] = 0;
	indices[1] = 0;
	indices[2] = 1;
	counter = 0;
	while (map[counter] && counter < MAP_SIZE - 1)
	{
		if (indices[2] && map[counter] == '\n')
			indices[2] = 0;
		else if (!indices[2])
		{
			if (map[counter] != '\n')
				matrix[indices[0]][indices[1]++] = map[counter];
			else
			{
				matrix[indices[0]][indices[1]] = '\0';
				indices[0]++;
				indices[1] = 0;
			}
		}
		counter++;
	}
	return (1);
}

char	**ft_map_to_matrix(char *map, int *matrix_size)
{
	char	**matrix;

	matrix = allocate_matrix(matrix_size);
	if (!matrix)
		return (NULL);
	if (!process_map_to_matrix(map, matrix))
		return (NULL);
	return (matrix);
}
