/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:35:39 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 14:19:15 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_bilist **slot_in, t_bilist **slot_out)
{
	t_bilist	*temp;

	if (!slot_out || !*slot_out)
		return ;
	temp = *slot_out;
	*slot_out = temp->next;
	if (*slot_out)
		(*slot_out)->pre = NULL;
	else
		*slot_out = NULL;
	temp->next = *slot_in;
	temp->pre = NULL;
	if (*slot_in)
		(*slot_in)->pre = temp;
	*slot_in = temp;
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
