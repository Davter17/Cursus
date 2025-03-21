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

int	main(int argc, char **argv)
{
	t_bilist		*slot_a;
	t_bilist		*slot_b;

	slot_b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	generate_slot(&slot_a, argv);
	if (slot_sorted(slot_a))
	{
		free(&slot_a);
		return (0);
	}
	if (slot_len(slot_a) <= 3)
		sort_three(&slot_a);
	else
		sort_slots(&slot_a, &slot_b);
	free(&slot_a);
	return (0);
}
