/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:25:08 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/12 06:22:34 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int	num_a;
	int	num_b;

	num_a = 0;
	num_b = 1;
	while (num_a <= 99)
	{
		while (num_b <= 99)
		{
			write(1, &"0123456789"[num_a / 10], 1);
			write(1, &"0123456789"[num_a % 10], 1);
			write(1, " ", 1);
			write(1, &"0123456789"[num_b / 10], 1);
			write(1, &"0123456789"[num_b % 10], 1);
			if (num_a != 98)
				write(1, ", ", 2);
			num_b++;
		}
		num_a++;
		num_b = num_a;
		num_b++;
	}
	return ;
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
