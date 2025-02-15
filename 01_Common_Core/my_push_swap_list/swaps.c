/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 14:19:32 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_bilist *slot)
{
	int			temp;
	t_bilist	*act;

	if (!slot)
		return ;
	act = slot;
	if (act->next)
	{
		temp = act->next->content;
		act->next->content = act->content;
		act->content = temp;
	}
}

void	sa(t_bilist *slot)
{
	swap(slot);
	write(1, "sa\n", 3);
}

void	sb(t_bilist *slot)
{
	swap(slot);
	write(1, "sb\n", 3);
}

void	ss(t_bilist *slot_a, t_bilist *slot_b)
{
	swap(slot_a);
	swap(slot_b);
	write(1, "ss\n", 3);
}
