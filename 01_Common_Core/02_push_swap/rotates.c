/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 17:49:10 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *slot)
{
	int	temp;
	int	i;

	if (slot[1])
	{
		i = 0;
		temp = slot[0];
		while (slot[i + 1])
		{
			slot[i] = slot[i + 1];
			i++;
		}
		slot[i] = temp;
	}
}

void	ra(int *slot)
{
	rotate(slot);
	write(1, "ra\n", 3);
}

void	rb(int *slot)
{
	rotate(slot);
	write(1, "rb\n", 3);
}

void	rr(int *slot_a, int *slot_b)
{
	rotate(slot_a);
	rotate(slot_b);
	write(1, "rr\n", 3);
}
