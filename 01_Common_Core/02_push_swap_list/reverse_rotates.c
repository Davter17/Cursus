/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 00:23:19 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(bi_t_list *slot)
{
	int		temp;
	bi_t_list	*act;

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

void	rra(bi_t_list *slot)
{
	reverse_rotate(slot);
	write(1, "rra\n", 4);
}

void	rrb(bi_t_list *slot)
{
	reverse_rotate(slot);
	write(1, "rrb\n", 4);
}

void	rrr(bi_t_list *slot_a, bi_t_list *slot_b)
{
	reverse_rotate(slot_a);
	reverse_rotate(slot_b);
	write(1, "rrr\n", 4);
}
