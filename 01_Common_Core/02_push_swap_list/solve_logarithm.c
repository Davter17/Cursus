/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_logarithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:59:03 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 11:51:12 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_last_three(bi_t_list *slot)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = slot->content;
	if (slot->next)
	{
		num_2 = slot->next->content;
		if (slot->next->next)
		{
			num_3 = slot->next->next->content;
			if (num_2 > num_3 && num_3 > num_1)
				rra(slot);
			if (num_2 > num_1 && num_1 > num_3)
				rra(slot);
			if (num_1 > num_3 && num_3 > num_2)
				ra(slot);
			if (num_1 > num_2 && num_2 > num_3)
				ra(slot);
		}
		if (slot->content > slot->next->content)
			sa(slot);
	}
}

void	solve_list(bi_t_list *slot_a, bi_t_list *slot_b)
{
	while (bilst_size(slot_a) > 3)
		pb(&slot_a, &slot_b);
	solve_last_three(slot_a);
	while (slot_b)
	{
		while (slot_b->content > slot_a->content || slot_b->content < bilst_last(slot_a)->content)
			ra(slot_a);
		pa(&slot_a, &slot_b);
	}
	while (slot_a->content > bilst_last(slot_a)->content)
		ra(slot_a);
}