/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:19:26 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 22:08:52 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	int	number;

	number = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
	{
		number *= ft_recursive_power(nb, power -1);
	}
	return (number);
}

/*
int	main(void)
{
	int	number;

	number = ft_recursive_power(3, 3);
	write(1, &"0123456789"[number / 100 % 10], 1);
	write(1, &"0123456789"[number / 10 % 10], 1);
	write(1, &"0123456789"[number % 10], 1);
	return (0);
}
*/
