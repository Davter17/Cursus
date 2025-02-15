/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/14 13:54:50 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node *slot)
{
	t_node	*act;
	int			temp;

	if (!slot || !slot->next)
		return ;
	act = slot;
	temp = act->content;
	while (act->next)
	{
		act->content = act->next->content;
		act = act->next;
	}
	act->content = temp;
}

void	ra(t_node *slot)
{
	rotate(slot);
	write(1, "ra\n", 3);
	bilst_print(slot);
}

void	rb(t_node *slot)
{
	rotate(slot);
	write(1, "rb\n", 3);
}

void	rr(t_node *slot_a, t_node *slot_b)
{
	rotate(slot_a);
	rotate(slot_b);
	write(1, "rr\n", 3);
}
