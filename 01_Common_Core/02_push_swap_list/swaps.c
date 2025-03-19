/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/16 05:52:04 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaps(t_node *slot)
{
	int			temp;
	t_node	*act;

	if (!slot)
		return ;
	act = slot;
	if (act->next)
	{
		temp = act->next->value;
		act->next->value = act->value;
		act->value = temp;
	}
}

void	sa(t_node *slot)
{
	swaps(slot);
	write(1, "sa\n", 3);
}

void	sb(t_node *slot)
{
	swaps(slot);
	write(1, "sb\n", 3);
}

void	ss(t_node *slot_a, t_node *slot_b)
{
	swaps(slot_a);
	swaps(slot_b);
	write(1, "ss\n", 3);
}
