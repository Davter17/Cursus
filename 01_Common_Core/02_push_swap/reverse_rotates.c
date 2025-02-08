/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 17:49:01 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *slot)
{
	int	temp;
	int	i;

	if (slot[1])
	{
		i = 0;
		while (slot[i + 1])
			i++;
		temp = slot[i];
		while (slot[i - 1])
		{
			slot[i] = slot[i - 1];
			i--;
		}
		slot[i] = temp;
	}
}

void	rra(int *slot)
{
	reverse_rotate(slot);
	write(1, "rra\n", 4);
}

void	rrb(int *slot)
{
	reverse_rotate(slot);
	write(1, "rrb\n", 4);
}

void	rrr(int *slot_a, int *slot_b)
{
	reverse_rotate(slot_a);
	reverse_rotate(slot_b);
	write(1, "rrr\n", 4);
}
