/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:07:09 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/19 14:14:21 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	matrix_print(int **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size - 1)
	{
		while (i < size - 1)
		{
			write(1, &matrix[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		i = 1;
		j++;
	}
}

void	matrix_print_error(void)
{
	write(1, "Error\n", 6);
}
