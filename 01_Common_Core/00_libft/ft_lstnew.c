/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:01:16 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 16:23:43 by mpico-bu         ###   ########.fr       */
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

/*
void	ft_plus(void *str)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	while(s[i])
	{
		s[i]++;
		i++;
	}
}

void *ft_plus2(void *str)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	while(s[i])
	{
		s[i]++;
		i++;
	}
	return((void *)s);
}


void del(void *i)
{
	free(i);
}

int main(void)
{
	t_list	**list;
	t_list	*print;
	t_list	*print2;
	t_list	*last;
	t_list	*second_last;
	int		i;
	int		list_size;

	//lstnew lstadd_back lstadd_front
	list = malloc(10 * sizeof(t_list **));
	ft_lstadd_front(list, ft_lstnew(ft_strdup("1")));
	ft_lstadd_back(list, ft_lstnew(ft_strdup("2")));
	ft_lstadd_front(list, ft_lstnew(ft_strdup("3")));
	ft_lstadd_back(list, ft_lstnew(ft_strdup("A")));
	
	//lst_last lst_delone 
	last = ft_lstlast(*list);
    second_last = *list;
    while (second_last && second_last->next != last)
        second_last = second_last->next;
    if (second_last)
        second_last->next = NULL;
    ft_lstdelone(last, del);
	
	// lstsize lst_iter
	print = *list;
	list_size = ft_lstsize(print);
	i = 0;
	while (i < list_size)
	{
		ft_lstiter(print, ft_plus);
		write(1, print->content, 1);
		print = print->next;
		i++;
	}

	//lst_map
	print2 = ft_lstmap(*list, ft_plus2, del);
    print = print2;
    list_size = ft_lstsize(print);
    i = 0;
    while (i < list_size)
    {
        write(1, print->content, 1);
        print = print->next;
        i++;
    }

	//lst_clear
	ft_lstclear(list, del);
	print = *list;
	list_size = ft_lstsize(print);
	i = 0;
	while (i < list_size)
	{
		write(1, print->content, 1);
		print = print->next;
		i++;
	}
	return (0);
}
*/