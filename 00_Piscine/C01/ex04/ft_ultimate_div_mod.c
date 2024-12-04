/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:37:03 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/11 10:36:07 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	value_a;
	int	value_b;

	value_a = *a;
	value_b = *b;
	*a = value_a / value_b;
	*b = value_a % value_b;
	return ;
}

/*
int	main(void)
{
	int	num_a;
	int	num_b;
	int	*ptr_num_a;
	int	*ptr_num_b;

	num_a = 62;
	num_b = 20;
	ptr_num_a = &num_a;
	ptr_num_b = &num_b;
	ft_ultimate_div_mod(ptr_num_a, ptr_num_b);
	write(1, &"0123456789"[num_a], 1);
	write(1, &"0123456789"[num_b], 1);
	return (0);
}
*/
