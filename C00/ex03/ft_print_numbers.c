/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:24:59 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/07 19:18:23 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	number;

	number = 0;
	while (number <= 9)
	{
		write(1, &("0123456789"[number]), 1);
		number++;
	}
	return ;
}

/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/
