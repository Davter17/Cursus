/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:19:12 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 23:21:59 by mpico-bu         ###   ########.fr       */
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

/*
int	main(void)
{
	int	number;

	number = ft_is_prime(144);
	write(1, &"0123456789"[number % 10], 1);
	return (0);
}
*/
