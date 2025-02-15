/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_logarithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:59:03 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/14 03:59:19 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_last_three(t_bilist *slot)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = slot->content;
	if (slot->next)
	{
		num_2 = slot->next->content;
		if (slot->next->next)
		{
			num_3 = slot->next->next->content;
			if (num_2 > num_3 && num_3 > num_1)
				rra(slot);
			if (num_2 > num_1 && num_1 > num_3)
				rra(slot);
			if (num_1 > num_3 && num_3 > num_2)
				ra(slot);
			if (num_1 > num_2 && num_2 > num_3)
				ra(slot);
		}
		if (slot->content > slot->next->content)
			sa(slot);
	}
}

void	solve_last_pass(t_bilist *slot_a, int min)
{
	int			i;
	t_bilist	*slot_act;

	slot_act = slot_a;
	i = 0;
	while (slot_act->content != min)
	{
		slot_act = slot_act->next;
		i++;
	}
	if (i / 2 < bilst_size(slot_a))
	{
		while (slot_a->content != min)
			rra(slot_a);
	}
	else
	{
		while (slot_a->content != min)
			ra(slot_a);
	}
}

int	bilst_index(t_bilist *list, t_bilist *node)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list == node)
			return (i);
		list = list->next;
		i++;
	}
	return (-1); // Retorna -1 si el nodo no está en la lista (caso de error)
}

void	solve_third_pass(t_bilist *slot_a, t_bilist *slot_b)
{
	t_bilist	*slot_act;
	int			i;
	int			int_b;

	while (slot_b)
	{
		int_b = slot_b->content;
		slot_act = slot_a;
		i = 0;
		while (i < bilst_size(slot_a) / 2)
		{
			if ((i == 0 && int_b < slot_act->content && int_b > bilst_last(slot_act)->content) ||
				(int_b < slot_act->content && int_b > slot_act->pre->content))
				{
					while(slot_a->content == slot_act->content)
						rra(slot_a);
					break ;
				}
			slot_act = slot_act->next;
			i++;
		}
		while(slot_a->content < int_b)
			ra(slot_a);
		pa(&slot_a, &slot_b);
	}
}

void	solve_list(t_bilist *slot_a, t_bilist *slot_b)
{
	int			max;
	int			min;

	max = bilst_max(slot_a);
	min = bilst_min(slot_a);
	while (bilst_size(slot_a) > 3)
	{
		while (slot_a->content == min || slot_a->content == max)
			ra(slot_a);
		pb(&slot_a, &slot_b);
	}
	solve_last_three(slot_a);
	solve_third_pass(slot_a, slot_b);
	solve_last_pass(slot_a, min);
}