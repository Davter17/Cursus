/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/14 13:54:32 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	generate_slot(t_node **slot_ini, int size, char **argv)
{
	int			i;
	t_node	*slot_act;
	t_node	*slot_fut;

	*slot_ini = bilst_new(NULL, ft_atoi(argv[1]));
	if (!slot_ini)
		return (ft_printf("Error\nMemory allocation failed.\n"), 0);
	slot_act = *slot_ini;
	i = 2;
	while (i <= size)
	{
		slot_fut = bilst_new(slot_act, ft_atoi(argv[i]));
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
	t_node	*slot_a;
	t_node	*slot_b;

	slot_a = NULL;
	slot_b = NULL;
	if (argc < 2)
		return (0);
	if (check_argv(argc, argv) == 0)
		return (fprintf(stderr, "Error\n"), 1);
	if (generate_slot(&slot_a, argc - 1, argv) == 0)
		return (fprintf(stderr, "Error\n"), 1);
	solve_list(slot_a, slot_b);
	free(slot_b);
	return (0);
}

// ARG="3 2 1 5 7 0 -5 12"; ./push_swap $=ARG | ./checker_linux $=ARG