/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:19:26 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 22:19:27 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fibonacci(int index)
{
	int	num_a;
	int	num_b;
	int	number;

	num_a = 0;
	num_b = 0;
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
	{
		number = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	}
	return (number);
}

/*
int	main(void)
{
	int	number;

	number = ft_fibonacci(10);
	write(1, &"0123456789"[number / 100 % 10], 1);
	write(1, &"0123456789"[number / 10 % 10], 1);
	write(1, &"0123456789"[number % 10], 1);
	return (0);
}
*/
