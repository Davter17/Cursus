/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:43:43 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/12 06:22:11 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	last_cycle(int num_1, int num_2, int num_3)
{
	while (num_3 <= 9)
	{
		if (num_2 < num_3)
		{
			write(1, &"0123456789"[num_1], 1);
			write(1, &"0123456789"[num_2], 1);
			write(1, &"0123456789"[num_3], 1);
			if (num_1 != 7)
				write(1, ", ", 2);
		}
		num_3++;
	}
}

void	ft_print_comb(void)
{
	int	num_a;
	int	num_b;
	int	num_c;

	num_a = 0;
	num_b = 0;
	num_c = 0;
	while (num_a <= 9)
	{
		while (num_b <= 9)
		{
			if (num_a < num_b)
			{
				last_cycle(num_a, num_b, num_c);
			}
			num_b++;
			num_c = 0;
		}
		num_a++;
		num_b = 0;
	}
	return ;
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
