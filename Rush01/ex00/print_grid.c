/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/19 20:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_row(int grid[4][4], int row)
{
	int		col;
	char	c;

	col = 0;
	while (col < 4)
	{
		c = '0' + grid[row][col];
		write(1, &c, 1);
		if (col < 3)
			write(1, " ", 1);
		col++;
	}
	write(1, "\n", 1);
}

void	print_grid(int grid[4][4])
{
	int	row;

	row = 0;
	while (row < 4)
	{
		print_row(grid, row);
		row++;
	}
}
