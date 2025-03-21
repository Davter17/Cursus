/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:35:39 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/14 03:56:03 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_bilist **slot_in, t_bilist **slot_out)
{
    t_bilist	*slot_in_first;
    t_bilist	*slot_out_first;

    slot_in_first = *slot_in;
    slot_out_first = *slot_out;
    if (slot_out_first)
    {
        if (slot_out_first->next)
        {
            *slot_out = slot_out_first->next;
            slot_out_first->next->prev = NULL;
        }
        else
            *slot_out = NULL;
    }
    else
        *slot_out = NULL;
	slot_out_first->next = slot_in_first;
	*slot_in = slot_out_first;
	if (slot_in_first)
		slot_in_first->prev = slot_out_first;
}


void	pa(t_bilist **slot_a, t_bilist **slot_b)
{
	push(slot_a, slot_b);
	write(1, "pa\n", 3);
}

void	pb(t_bilist **slot_a, t_bilist **slot_b)
{
	push(slot_b, slot_a);
	write(1, "pb\n", 3);
}
