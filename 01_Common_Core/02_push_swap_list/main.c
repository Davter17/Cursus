/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/10 01:17:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew2(t_list *prev, int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->pre = prev;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	generate_slot(t_list **slot_ini, int size, char **argv)
{
	int		i;
	t_list	*slot_act;
	t_list	*slot_fut;

	*slot_ini = ft_lstnew2(NULL, atoi(argv[1]));
	slot_act = *slot_ini;
	i = 2;
	while (i <= size)
	{
		slot_fut = ft_lstnew2(slot_act, atoi(argv[i]));
		if (!slot_fut)
			return (0);
		slot_act->next = slot_fut;
		slot_act = slot_fut;
		i++;
	}
	return (1);
}

void	print_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*slot_a;
	t_list	*slot_b;

	slot_a = NULL;
	slot_b = NULL;
	if (argc < 2)
		return (0);
	if (generate_slot(&slot_a, argc - 1, argv) == 0)
	{
		printf("Error\nFallo en la asignación de memoria.\n");
		return (1);
	}
	print_list(slot_a);
	sa(slot_a);
	print_list(slot_a);
	pb(&slot_a, &slot_b);
	pb(&slot_a, &slot_b);
	pb(&slot_a, &slot_b);
	print_list(slot_a);
	rr(slot_a, slot_b);
	print_list(slot_a);
	rrr(slot_a, slot_b);
	print_list(slot_a);
	sa(slot_a);
	print_list(slot_a);
	pa(&slot_a, &slot_b);
	pa(&slot_a, &slot_b);
	pa(&slot_a, &slot_b);
	print_list(slot_a);
	free(slot_a);
	free(slot_b);
	return (0);
}
