/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:20:26 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 23:25:38 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	counter;
	int	div;

	counter = 2;
	if (nb < 2)
		return (0);
	while (counter <= nb / 2)
	{
		div = nb / counter;
		if (div * counter == nb)
			return (0);
		counter++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

/*
int	main(void)
{
	int	number;

	number = ft_find_next_prime(354);
	write(1, &"0123456789"[number / 100 % 10], 1);
	write(1, &"0123456789"[number / 10 % 10], 1);
	write(1, &"0123456789"[number % 10], 1);
	return (0);
}
*/
