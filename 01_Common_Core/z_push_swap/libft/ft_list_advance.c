/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_advance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:02:23 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/11 19:21:30 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes a node and frees its content.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// Clears the entire list and frees all nodes.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		del(aux->content);
		free(aux);
	}
}

// Iterates over the list and applies the function to each node's content.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	f(lst->content);
	if (lst->next != NULL)
		ft_lstiter(lst->next, f);
}

// Creates a new list by applying the function to each node's content.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*lst2_sub;

	if (!lst || !f || !del)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		lst2_sub = ft_lstnew(f(lst->content));
		if (!lst2_sub)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, lst2_sub);
		lst = lst->next;
	}
	return (lst2);
}
