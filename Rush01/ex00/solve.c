/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/19 20:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_row(int grid[4][4], int row, int num);
int	is_valid_col(int grid[4][4], int col, int num);
int	count_visible_row(int grid[4][4], int row, int from_left);
int	count_visible_col(int grid[4][4], int col, int from_top);

int	check_clues(int grid[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (count_visible_col(grid, i, 1) != clues[i])
			return (0);
		if (count_visible_col(grid, i, 0) != clues[4 + i])
			return (0);
		if (count_visible_row(grid, i, 1) != clues[8 + i])
			return (0);
		if (count_visible_row(grid, i, 0) != clues[12 + i])
			return (0);
		i++;
	}
	return (1);
}

int	solve_recursive(int grid[4][4], int clues[16], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_clues(grid, clues));
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid_row(grid, row, num) && is_valid_col(grid, col, num))
		{
			grid[row][col] = num;
			if (solve_recursive(grid, clues, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	solve(int grid[4][4], int clues[16])
{
	return (solve_recursive(grid, clues, 0));
}
