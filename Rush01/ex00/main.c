/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:38:46 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/19 20:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		parse_input(char *str, int *clues);
int		solve(int grid[4][4], int clues[16]);
void	print_grid(int grid[4][4]);
void	print_error(void);
void	init_grid(int grid[4][4]);

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	if (!parse_input(argv[1], clues))
	{
		print_error();
		return (1);
	}
	init_grid(grid);
	if (!solve(grid, clues))
	{
		print_error();
		return (1);
	}
	print_grid(grid);
	return (0);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
