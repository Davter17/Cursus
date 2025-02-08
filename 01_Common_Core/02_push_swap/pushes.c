/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:35:39 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 18:02:53 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *slot_in, int *slot_out)
{
	int	i;

	if (slot_out[0])
	{
		i = 0;
		while (slot_in[i])
			i++;
		while (i >= 0)
		{
			slot_in[i + 1] = slot_in[i];
			i--;
		}
		slot_in[0] = slot_out[0];
		i = 0;
		while (slot_out[i])
		{
			slot_out[i] = slot_out[i + 1];
			i++;
		}
	}
}

void	pa(int *slot_a, int *slot_b)
{
	push(slot_a, slot_b);
	write(1, "pa\n", 3);
}

void	pb(int *slot_a, int *slot_b)
{
	push(slot_b, slot_a);
	write(1, "pb\n", 3);
}
