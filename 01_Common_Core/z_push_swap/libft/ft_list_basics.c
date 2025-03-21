/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:17:36 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/11 19:36:28 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Creates a new list node with the given content.
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// Adds a new node at the beginning of the list.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// Adds a new node at the end of the list.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lstlast = *lst;
	while (lstlast->next != NULL)
		lstlast = lstlast->next;
	lstlast->next = new;
}

// Returns the size of the list.
int	ft_lstsize(t_list *lst)
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

// Returns the last node of the list.
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
