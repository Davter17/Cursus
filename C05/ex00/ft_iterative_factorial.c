/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:01:20 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/20 10:30:39 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	number;

	number = 1;
	if (nb < 0)
		return (0);
	while (nb != 0)
	{
		number = number * nb;
		nb--;
	}
	return (number);
}

/*
int	main(void)
{
	int	number;

	number = ft_iterative_factorial(-1);
	write(1, &"0123456789"[number / 100 % 10], 1);
	write(1, &"0123456789"[number / 10 % 10], 1);
	write(1, &"0123456789"[number % 10], 1);
	return (0);
}
*/
