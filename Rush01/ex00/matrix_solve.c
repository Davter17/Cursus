/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:07:09 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/16 16:29:38 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**matrix_solve_comprobe_4_vert(int **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (matrix[0][i] == '4' || matrix[size - 1][i] == '4')
		{
			j = 1;
			while (j <= 4 && j < size)
			{
				if (matrix[0][i] == size - 2)
					matrix[j][i] = '0' + j;
				else
					matrix[j][i] = '0' + j;
				j++;
			}
		}
		i++;
	}
	return (matrix);
}

int	**matrix_solve_comprobe_4_hori(int **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (matrix[i][0] == '4' || matrix[i][size - 1] == '4')
		{
			j = 1;
			while (j <= 4 && j < size)
			{
				if (matrix[i][0] == size -2)
					matrix[i][j] = '0' + j;
				else
					matrix[i][j] = '0' + j;
				j++;
			}
		}
		i++;
	}
	return (matrix);
}

int	**matrix_solve(int **matrix, int size)
{
	matrix = matrix_solve_comprobe_4_vert(matrix, size);
	matrix = matrix_solve_comprobe_4_hori(matrix, size);
	return (matrix);
}
