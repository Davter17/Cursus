/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:34 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/10 01:16:51 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *slot)
{
	t_list	*act;
	int		temp;

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

void	ra(t_list *slot)
{
	rotate(slot);
	write(1, "ra\n", 3);
}

void	rb(t_list *slot)
{
	rotate(slot);
	write(1, "rb\n", 3);
}

void	rr(t_list *slot_a, t_list *slot_b)
{
	rotate(slot_a);
	rotate(slot_b);
	write(1, "rr\n", 3);
}
