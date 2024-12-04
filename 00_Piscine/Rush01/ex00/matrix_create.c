/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:07:09 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/17 21:36:29 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**matrix_create_prototype(int size)
{
	int	**matrix;
	int	i;
	int	j;

	i = 0;
	j = 0;
	matrix = (int **)malloc(size * sizeof(int *));
	while (i < size)
	{
		matrix[i] = (int *)malloc(size * sizeof(int));
		i++;
	}
	return (matrix);
}

int	**matrix_create_up_down(char *str, int size, int **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		if ((j == 0 || j == size - 1) && (i != 0 && i != size - 1))
		{
			matrix[j][i] = *str;
			str += 2;
		}
		else
			matrix[j][i] = '0';
		i++;
		if (i == size)
		{
			i = 0;
			j++;
		}
	}
	return (matrix);
}

int	**matrix_create_left_right(char *str, int size, int **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		if ((i == 0) && (j != 0 && j != size - 1))
		{
			matrix[j][i] = *str;
			matrix[j][i + size - 1] = *(str + ((size - 2) * 2));
			str += 2;
		}
		i++;
		if (i == size - 1)
		{
			i = 0;
			j++;
		}
	}
	return (matrix);
}

int	**matrix_create(char *str, int size)
{
	int	**matrix;

	matrix = matrix_create_prototype(size);
	matrix = matrix_create_up_down(str, size, matrix);
	matrix = matrix_create_left_right(str, size, matrix);
	return (matrix);
}
