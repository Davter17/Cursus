/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/14 03:56:11 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_bilist *slot)
{
	t_bilist	*act;
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

void	ra(t_bilist *slot)
{
	rotate(slot);
	write(1, "ra\n", 3);
	bilst_print(slot);
}

void	rb(t_bilist *slot)
{
	rotate(slot);
	write(1, "rb\n", 3);
}

void	rr(t_bilist *slot_a, t_bilist *slot_b)
{
	rotate(slot_a);
	rotate(slot_b);
	write(1, "rr\n", 3);
}
