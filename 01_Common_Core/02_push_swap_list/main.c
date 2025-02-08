/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 20:03:45 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(t_list *prev, int *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->pre = prev;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list	**generate_slot(t_list **slot_ini, int size, char **argv)
{
	int		i;
	t_list	*slot_act;
	t_list	*slot_fut;
	
	i = 0;
	while (i < size)
	{
		if (i == 0)
		{
			slot_act = ft_lstnew(NULL, ft_atoi(argv[i]));
			continue ;
		}
		slot_act = ft_lstnew(slot_act, ft_atoi(argv[i]));
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_list	**slot_a;
	t_list	**slot_b;

	slot_a = NULL;
	slot_b = NULL;
	if (argc > 1)
	{
		if (generate_slots(slot_a, argc - 1, argv) == 0)
		{
			printf("Error: No allocation memory\n");
			return (1);
		}
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
