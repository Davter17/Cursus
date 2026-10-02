/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:19:26 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 22:09:08 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	number;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	number = 1;
	while (power != 0)
	{
		number *= nb;
		power--;
	}
	return (number);
}

/*
int	main(void)
{
	int	number;

	number = ft_iterative_power(2, 5);
	write(1, &"0123456789"[number / 10], 1);
	write(1, &"0123456789"[number % 10], 1);
	return (0);
}
*/
