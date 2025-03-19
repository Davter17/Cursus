/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/17 19:07:39 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	generate_slot(t_bilist **slot_ini, int size, char **argv)
{
	int			i;
	t_bilist	*slot_act;
	t_bilist	*slot_fut;

	*slot_ini = bilst_new(NULL, ft_atoi(argv[1]), *slot_ini);
	if (!slot_ini)
		return (ft_printf("Error\nMemory allocation failed.\n"), 0);
	slot_act = *slot_ini;
	i = 2;
	while (i <= size)
	{
		slot_fut = bilst_new(slot_act, ft_atoi(argv[i]), slot_ini);
		if (!slot_fut)
			return (ft_printf("Error\nMemory allocation failed.\n"), 0);
		slot_act->next = slot_fut;
		slot_act = slot_fut;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_bilist		*a;
	t_bilist		*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc = 2)
		argv = split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a)  == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stracks(&a, &b);
	}
	free(&a);
	return (0);
}