/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:19:26 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 21:05:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	int	number;

	number = nb;
	if (nb == 0)
		number = 1;
	if (nb < 0)
		return (0);
	if (nb > 1)
	{
		nb--;
		number *= ft_recursive_factorial(nb);
	}
	return (number);
}

/*
int main(void)
{
    int number;

    number = ft_recursive_factorial(5);
    write(1, &"0123456789"[number / 100 % 10], 1);
    write(1, &"0123456789"[number / 10 % 10], 1);
    write(1, &"0123456789"[number % 10], 1);
    return (0);
}
*/
