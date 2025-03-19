/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:51 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/18 21:55:46 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_bilist *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->upper = false;
		if (i <= median)
			stack->upper = true;
		stack = stack->next;
		i++;
	}		
}

void	set_target_a(t_bilist *a, t_bilist *b)
{
	t_bilist	*current_b;
	t_bilist	*target_node;
	long		best_match_index;

	while (a)
	{
		best_match_index = -1;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == -1)
			a->target = find_max(b);
		else
			b->target = target_node;
		a = a->next;
	}
}

void update_cost(t_bilist *a, t_bilist *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->upper))
			a->push_cost = len_a - (a->index);
		if (a->target->upper)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	update_cheapest(t_bilist *stack)
{
	t_bilist	*cheapest_node;

	if (!stack)
		return ;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest_node->push_cost)
			cheapest_node = stack;
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_bilist *a, t_bilist *b)
{
	update_index(a);
	update_index(b);
	set_target_a(a, b);
	update_cost(a, b);
	update_cheapest(a);
}