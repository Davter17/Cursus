/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:38:46 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/16 16:21:55 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**matrix_create(char *str, int size);
int		**matrix_solve(int **matrix, int size);
void	matrix_print(int **matrix, int size);
void	matrix_print_error(void);

int	main(int argc, char **argv)
{
	int	**matrix[6][6];

	if (argc == 2)
	{
		**matrix = matrix_create(argv[1], 6);
		**matrix = matrix_solve(**matrix, 6);
		matrix_print(**matrix, 6);
	}
	else
		matrix_print_error();
	return (0);
}
