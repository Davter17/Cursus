/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 19:22:29 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	generate_slots(int **slot_a, int **slot_b, int size, char **argv)
{
	int	i;

	*slot_a = malloc((size + 1) * sizeof(int));
	if (!*slot_a)
		return (0);
	*slot_b = malloc((size + 1) * sizeof(int));
	if (!*slot_b)
		return (free(*slot_a), 0);
	i = 0;
	while (i < size)
	{
		(*slot_a)[i] = ft_atoi(argv[i + 1]);
		(*slot_b)[i] = 0;
		i++;
	}
	(*slot_a)[i] = 0;
	return (1);
}

void	order_slot(int *slot_a, int *slot_b)
{
	int	i;
	int	total;

	i = 0;
	while (slot_a[i + 1])
	{
		if (slot_a[i] > slot_a[i + 1])
		{
			while(i > 0)
			{
				pb(slot_a, slot_b);
				i--;
			}
			sa(slot_a);
			while(slot_b[0])
				pa(slot_a, slot_b);
			i = -1;
		}
		i++;
	}
}

void	print_slot(int *slot)
{
	int	i;

	i = 0;
	while (slot[i])
	{
		printf("%i ", slot[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int	*slot_a;
	int	*slot_b;

	slot_a = NULL;
	slot_b = NULL;
	if (argc > 1)
	{
		if (generate_slots(&slot_a, &slot_b, argc - 1, argv) == 0)
		{
			printf("Error: No allocation memory\n");
			return (1);
		}
		order_slot(slot_a, slot_b);
		print_slot(slot_a);
		free(slot_a);
		free(slot_b);
	}
	else
	{
		printf("Error: You must put at least 1 integer\n");
		return (1);
	}
	return (0);
}
