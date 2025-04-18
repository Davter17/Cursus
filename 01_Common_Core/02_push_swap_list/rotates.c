/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/16 05:52:21 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotates(t_node *slot)
{
	t_node	*act;
	int			temp;

	if (!slot || !slot->next)
		return ;
	act = slot;
	temp = act->value;
	while (act->next)
	{
		act->value = act->next->value;
		act = act->next;
	}
	act->value = temp;
}

void	ra(t_node *slot)
{
	rotates(slot);
	write(1, "ra\n", 3);
}

void	rb(t_node *slot)
{
	rotates(slot);
	write(1, "rb\n", 3);
}

void	rr(t_node *slot_a, t_node *slot_b)
{
	rotates(slot_a);
	rotates(slot_b);
	write(1, "rr\n", 3);
}
