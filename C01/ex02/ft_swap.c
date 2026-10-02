/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:48:48 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/11 10:36:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	num_aux;

	num_aux = *a;
	*a = *b;
	*b = num_aux;
}

/*
int	main(void)
{
	int	num_1;
	int	num_2;
	int	*ptr_1;
	int	*ptr_2;

	num_1 = 5;
	num_2 = 1;
	ptr_1 = &num_1;
	ptr_2 = &num_2;
	ft_swap(ptr_1, ptr_2);
	write(1, &"0123456789"[num_1], 1);
	write (1, &"0123456789"[num_2], 1);
	return (0);
}
*/
/*
int	main(void)
{
	int	num_1;
	int	num_2;
	int	*ptr_1;
	int	*ptr_2;

	num_1 = 34;
	num_2 = 12;
	ptr_1 = &num_1;
	ptr_2 = &num_2;
	ft_swap(ptr_1, ptr_2);
	write(1, &"0123456789"[num_1 / 10], 1);
	write(1, &"0123456789"[num_1 % 10], 1);
	write(1, &"0123456789"[num_2 / 10], 1);
	write(1, &"0123456789"[num_2 % 10], 1);
	return (0);
}
*/
