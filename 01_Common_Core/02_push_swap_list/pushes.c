/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:35:39 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 00:23:06 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(bi_t_list **slot_in, bi_t_list **slot_out)
{
	bi_t_list	*temp;

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

void	pa(bi_t_list **slot_a, bi_t_list **slot_b)
{
	push(slot_a, slot_b);
	write(1, "pa\n", 3);
}

void	pb(bi_t_list **slot_a, bi_t_list **slot_b)
{
	push(slot_b, slot_a);
	write(1, "pb\n", 3);
}
