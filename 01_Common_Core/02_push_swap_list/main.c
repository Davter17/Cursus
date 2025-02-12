/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 11:32:39 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	generate_slot(bi_t_list **slot_ini, int size, char **argv)
{
	int		i;
	bi_t_list	*slot_act;
	bi_t_list	*slot_fut;

	*slot_ini = bilst_new(NULL, atoi(argv[1]));
	slot_act = *slot_ini;
	i = 2;
	while (i <= size)
	{
		slot_fut = bilst_new(slot_act, atoi(argv[i]));
		if (!slot_fut)
			return (0);
		slot_act->next = slot_fut;
		slot_act = slot_fut;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	bi_t_list	*slot_a;
	bi_t_list	*slot_b;

	slot_a = NULL;
	slot_b = NULL;
	if (argc < 2)
		return (0);
	if (check_argv(argv) == 0)
		return (1);
	if (generate_slot(&slot_a, argc - 1, argv) == 0)
	{
		ft_printf("Error\nFallo en la asignación de memoria.\n");
		return (1);
	}
	bilst_print(slot_a);
	solve_list(slot_a, slot_b);
	bilst_print(slot_a);
	free(slot_b);
	return (0);
}
