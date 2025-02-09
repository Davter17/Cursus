/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 17:15:10 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **slot)
{
	int		temp;
	t_list	*ini;

	ini = *slot;
	if (ini->next)
	{
		temp = ini->next->content;
		ini->next->content = ini->content;
		ini->content = temp;
	}
}

void	sa(t_list **slot)
{
	swap(slot);
	write(1, "sa\n", 3);
}

void	sb(t_list **slot)
{
	swap(slot);
	write(1, "sb\n", 3);
}

void	ss(t_list **slot_a, t_list **slot_b)
{
	swap(slot_a);
	swap(slot_b);
	write(1, "ss\n", 3);
}
