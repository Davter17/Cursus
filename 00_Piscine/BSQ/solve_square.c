/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:17:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/25 22:20:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	check_obstacle(char **matrix, int *start, int *mat_size, char *par)
{
	int	i;
	int	j;

	i = start[0] - 1;
	while (++i < start[0] + start[2] && i < mat_size[0])
	{
		j = start[1] - 1;
		while (++j < start[1] + start[2] && j < mat_size[1])
		{
			if (matrix[i][j] == par[1])
				return (1);
		}
	}
	return (0);
}

int	check_bounds(int *start, int *mat_size)
{
	if (start[0] + start[2] > mat_size[0]
		|| start[1] + start[2] > mat_size[1])
		return (1);
	return (0);
}

int	*ft_calculate_size(char **matrix, int *start, int *mat_size, char *par)
{
	int	finish;

	finish = 0;
	while (finish == 0)
	{
		start[2]++;
		if (check_obstacle(matrix, start, mat_size, par)
			|| check_bounds(start, mat_size))
		{
			start[2]--;
			finish = 1;
		}
	}
	return (start);
}

int	*ft_find_next_square(char **matrix, int *start, int *mat_size, char *par)
{
	while (start[0] < mat_size[0] && matrix[start[0]][start[1]] != par[0])
	{
		if (start[1] + 1 < mat_size[1])
			start[1]++;
		else
		{
			start[0]++;
			start[1] = 0;
		}
	}
	if (start[0] < mat_size[0])
		start = ft_calculate_size(matrix, start, mat_size, par);
	return (start);
}

int	*ft_solve_square(char **matrix, int *start, int *mat_size, char *par)
{
	int	start_max[3];

	start_max[0] = 0;
	start_max[1] = 0;
	start_max[2] = 0;
	while (start[0] < mat_size[0])
	{
		while (start[1] < mat_size[1])
		{
			start = ft_find_next_square(matrix, start, mat_size, par);
			if (start[2] > start_max[2])
			{
				start_max[0] = start[0];
				start_max[1] = start[1];
				start_max[2] = start[2];
			}
			start[1]++;
		}
		start[0]++;
		start[1] = 0;
	}
	start[0] = start_max[0];
	start[1] = start_max[1];
	start[2] = start_max[2];
	return (start);
}
