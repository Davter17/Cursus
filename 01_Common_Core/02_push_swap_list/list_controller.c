/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:51 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/08 14:02:44 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*bilst_new(t_node *prev, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->pre = prev;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	bilst_size(t_node *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}

t_node	*bilst_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	bilst_min(t_node *lst)
{
	int	min;

	min = lst->value;
	while (lst->next)
	{
		lst = lst->next;
		if (min > lst->value)
			min = lst->value;
	}
	return (min);
}

int	bilst_max(t_node *lst)
{
	int	max;

	max = lst->value;
	while (lst->next)
	{
		lst = lst->next;
		if (max < lst->value)
			max = lst->value;
	}
	return (max);
}

void	bilst_print(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}
