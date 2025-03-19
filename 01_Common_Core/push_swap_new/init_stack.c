/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:51 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/17 21:18:26 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long ft_atol(const char *s)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	while(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while(s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

static void append_node(t_bilist **stack, int nbr)
{
	t_bilist	*new_node;
	t_bilist	*last_node;

	if (!stack)
		return ;
	new_node = malloc(1 * sizeof(t_bilist));
	if (!new_node)
		return ;
	new_node->value = nbr;
	new_node->next = NULL;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack(t_bilist **a, char *argv)
{
	long	n;
	long	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}