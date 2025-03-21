/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/14 03:56:08 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_bilist **slot)
{
	t_bilist	*first_node;
	t_bilist	*last_node;

	first_node = *slot;
	last_node = slot_last(first_node);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*slot = last_node;
}

void	rra(t_bilist **slot)
{
	reverse_rotate(slot);
	write(1, "rra\n", 4);
}

void	rrb(t_bilist **slot)
{
	reverse_rotate(slot);
	write(1, "rrb\n", 4);
}

void	rrr(t_bilist **slot_a, t_bilist **slot_b)
{
	reverse_rotate(slot_a);
	reverse_rotate(slot_b);
	write(1, "rrr\n", 4);
}
