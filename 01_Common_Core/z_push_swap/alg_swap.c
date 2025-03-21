/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 14:19:32 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_bilist **slot)
{
	t_bilist	*first_node;
	t_bilist	*second_node;

	first_node = *slot;
	second_node = first_node->next;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	if (first_node->next)
		first_node->next->prev = first_node;
	second_node->prev = NULL;
	second_node->next = first_node;
	*slot = second_node;
}

void	sa(t_bilist **slot)
{
	swap(slot);
	write(1, "sa\n", 3);
}

void	sb(t_bilist **slot)
{
	swap(slot);
	write(1, "sb\n", 3);
}

void	ss(t_bilist **slot_a, t_bilist **slot_b)
{
	swap(slot_a);
	swap(slot_b);
	write(1, "ss\n", 3);
}
