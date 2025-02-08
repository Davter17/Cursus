/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 17:15:10 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *slot)
{
	int	temp;

	if (slot[1])
	{
		temp = slot[1];
		slot[1] = slot[0];
		slot[0] = temp;
	}
}

void	sa(int *slot)
{
	swap(slot);
	write(1, "sa\n", 3);
}

void	sb(int *slot)
{
	swap(slot);
	write(1, "sb\n", 3);
}

void	ss(int *slot_a, int *slot_b)
{
	swap(slot_a);
	swap(slot_b);
	write(1, "ss\n", 3);
}
