/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logarithm_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:51 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/18 21:56:21 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_last_three(t_bilist *stack)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = stack->value;
	if (stack->next)
	{
		num_2 = stack->next->value;
		if (stack->next->next)
		{
			num_3 = stack->next->next->value;
			if (num_1 > num_2 && num_2 > num_3)
				ra(stack);
			else if (num_1 > num_3 && num_3 > num_2)
				ra(stack);
			else if (num_2 > num_1 && num_1 > num_3)
				rra(stack);
			else if (num_2 > num_3 && num_3 > num_1)
				rra(stack);
		}
		if (stack->value > stack->next->value)
			sa(stack);
	}
}

void prep_for_push(t_bilist **stack, t_bilist *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->upper)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->upper)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	move_a_to_b(t_bilist **a, t_bilist **b)
{
	t_bilist	*cheapest_node;
	
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->upper && cheapest_node->target->upper)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->upper) && !(cheapest_node->target->upper))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_bilist **a, t_bilist **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

void	min_on_top(t_bilist **a)
{
	while((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->upper)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_bilist **a, t_bilist **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while(len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}