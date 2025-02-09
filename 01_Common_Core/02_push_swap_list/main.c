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

t_list	*ft_lstnew(t_list *prev, int content)
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

void	generate_slot(t_list **slot_ini, int size, char **argv)
{
	int		i;
	t_list	*slot_act;
	t_list	*slot_fut;

	*slot_ini = ft_lstnew(NULL, atoi(argv[1]));
	slot_act = *slot_ini;
	i = 2;
	while (i <= size)
	{
		slot_fut = ft_lstnew(slot_act, atoi(argv[i]));
		if (!slot_fut)
			return ;
		slot_act->next = slot_fut;
		slot_act = slot_fut;
		i++;
	}
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

	slot_a = NULL;
	if (argc < 2)
		return (printf("Error: You must put at least 1 integer\n"), 1);
	generate_slot(&slot_a, argc - 1, argv);
	if (!slot_a)
		return (printf("Error: No memory allocation\n"), 1);
	sa(&slot_a);
	print_list(slot_a);
	return (0);
}
