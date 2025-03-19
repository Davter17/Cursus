/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_logarithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:59:03 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/16 05:52:57 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_last_three(t_node *slot)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = slot->value;
	if (slot->next)
	{
		num_2 = slot->next->value;
		if (slot->next->next)
		{
			num_3 = slot->next->next->value;
			if (num_1 > num_2 && num_2 > num_3)
				ra(slot);
			else if (num_1 > num_3 && num_3 > num_2)
				ra(slot);
			else if (num_2 > num_1 && num_1 > num_3)
				rra(slot);
			else if (num_2 > num_3 && num_3 > num_1)
				rra(slot);
		}
		if (slot->value > slot->next->value)
			sa(slot);
	}
}

void	solve_last_pass(t_node *slot_a, int min)
{
	int			i;
	t_node	*slot_act;

	slot_act = slot_a;
	i = 0;
	while (slot_act->value != min)
	{
		slot_act = slot_act->next;
		i++;
	}
	if (i / 2 < bilst_size(slot_a))
	{
		while (slot_a->value != min)
			rra(slot_a);
	}
	else
	{
		while (slot_a->value != min)
			ra(slot_a);
	}
}

int	bilst_index(t_node *list, t_node *node)
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

t_node	*solve_third_pass(t_node *slot_a, t_node *slot_b)
{
	int		int_b;
	int		i;
	t_node	*slot_act;
	
	while (slot_b)
	{
		int_b = slot_b->value;
		slot_act = slot_a;
		i = 0;
		while (i < bilst_size(slot_a) / 2)
		{
			if ((i == 0 && int_b < slot_act->value && int_b > bilst_last(slot_act)->value) ||
				(int_b < slot_act->value && int_b > slot_act->pre->value))
				{
					while (slot_a->value != int_b && slot_a->value != slot_act->value)
						rra(slot_a);
					break ;
				}
			slot_act = slot_act->next;
			i++;
		}
		while(slot_a->value < int_b)
			ra(slot_a);
		pa(&slot_a, &slot_b);
	}
	return(slot_a);
}

void	solve_list(t_node *slot_a, t_node *slot_b)
{
	int			max;
	int			min;

	max = bilst_max(slot_a);
	min = bilst_min(slot_a);
	while (bilst_size(slot_a) > 3)
	{
		while (slot_a->value == min || slot_a->value == max)
			ra(slot_a);
		pb(&slot_a, &slot_b);
	}
	solve_last_three(slot_a);
	write(1, "1\n", 2);
	slot_a = solve_third_pass(slot_a, slot_b);
	write(1, "1\n", );
	solve_last_pass(slot_a, min);
	//bilst_print(slot_a);
}