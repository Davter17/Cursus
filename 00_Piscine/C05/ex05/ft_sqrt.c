/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:19:26 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 22:25:25 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt * sqrt <= nb)
	{
		if (sqrt * sqrt == nb)
			return (sqrt);
		sqrt++;
	}
	return (0);
}

/*
int	main(void)
{
	int	number;

	number = ft_sqrt(144);
	write(1, &"0123456789"[number / 100 % 10], 1);
	write(1, &"0123456789"[number / 10 % 10], 1);
	write(1, &"0123456789"[number % 10], 1);
	return (0);
}
*/
