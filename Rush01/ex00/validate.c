/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/19 20:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_row(int grid[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (grid[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	is_valid_col(int grid[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (grid[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	count_visible_row(int grid[4][4], int row, int from_left)
{
	int	visible;
	int	max;
	int	col;
	int	idx;

	visible = 0;
	max = 0;
	col = 0;
	while (col < 4)
	{
		if (from_left)
			idx = col;
		else
			idx = 3 - col;
		if (grid[row][idx] > max)
		{
			max = grid[row][idx];
			visible++;
		}
		col++;
	}
	return (visible);
}

int	count_visible_col(int grid[4][4], int col, int from_top)
{
	int	visible;
	int	max;
	int	row;
	int	idx;

	visible = 0;
	max = 0;
	row = 0;
	while (row < 4)
	{
		if (from_top)
			idx = row;
		else
			idx = 3 - row;
		if (grid[idx][col] > max)
		{
			max = grid[idx][col];
			visible++;
		}
		row++;
	}
	return (visible);
}
