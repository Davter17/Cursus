/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/16 05:52:13 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotates(t_node *slot)
{
	int		temp;
	t_node	*act;

	if (!slot || !slot->next)
		return ;
	act = slot;
	while (act->next)
		act = act->next;
	temp = act->value;
	while (act->pre)
	{
		act->value = act->pre->value;
		act = act->pre;
	}
	act->value = temp;
}

void	rra(t_node *slot)
{
	reverse_rotates(slot);
	write(1, "rra\n", 4);
}

void	rrb(t_node *slot)
{
	reverse_rotates(slot);
	write(1, "rrb\n", 4);
}

void	rrr(t_node *slot_a, t_node *slot_b)
{
	reverse_rotates(slot_a);
	reverse_rotates(slot_b);
	write(1, "rrr\n", 4);
}
