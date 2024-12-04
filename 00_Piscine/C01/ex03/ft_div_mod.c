/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:17:50 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/11 10:36:04 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int	main(void)
{
	int	num_a;
	int	num_b;
	int	div;
	int	mod;
	int	*pnt_div;
	int	*pnt_mod;

	num_a = 50;
	num_b = 23;
	pnt_div = &div;
	pnt_mod = &mod;
	ft_div_mod(num_a, num_b, pnt_div, pnt_mod);
	write(1, &"0123456789"[div], 1);
	write(1, &"0123456789"[mod], 1);
	return (0);
}
*/
