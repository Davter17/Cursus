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

void	reverse_rotate(t_bilist *slot)
{
	int			temp;
	t_bilist	*act;

	if (!slot || !slot->next)
		return ;
	act = slot;
	while (act->next)
		act = act->next;
	temp = act->content;
	while (act->pre)
	{
		act->content = act->pre->content;
		act = act->pre;
	}
	act->content = temp;
}

void	rra(t_bilist *slot)
{
	reverse_rotate(slot);
	write(1, "rra\n", 4);
	bilst_print(slot);
}

void	rrb(t_bilist *slot)
{
	reverse_rotate(slot);
	write(1, "rrb\n", 4);
}

void	rrr(t_bilist *slot_a, t_bilist *slot_b)
{
	reverse_rotate(slot_a);
	reverse_rotate(slot_b);
	write(1, "rrr\n", 4);
}
