/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_board(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_safe(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (board[i] - i == row - col)
			return (0);
		if (board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve(int *board, int col)
{
	int	row;
	int	count;

	count = 0;
	if (col == 10)
	{
		ft_print_board(board);
		return (1);
	}
	row = 0;
	while (row < 10)
	{
		if (ft_is_safe(board, col, row))
		{
			board[col] = row;
			count += ft_solve(board, col + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		board[i] = -1;
		i++;
	}
	return (ft_solve(board, 0));
}

/*
int	main(void)
{
	int	solutions;

	solutions = ft_ten_queens_puzzle();
	return (0);
}
*/
