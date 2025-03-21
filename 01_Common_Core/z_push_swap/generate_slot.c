/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_slot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/17 19:07:39 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bilist	*bilst_new(t_bilist *prev, int value)
{
	t_bilist	*new_node;

	new_node = malloc(sizeof(t_bilist));
	if (!new_node)
		return (NULL);
	new_node->prev = prev;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static	void free_slots(t_bilist *slot_ini)
{
	t_bilist	*temp;

	while (slot_ini)
	{
		temp = slot_ini;
		slot_ini = slot_ini->next;
		free(temp);
	}
}

void	generate_slot(t_bilist **slot_ini, char **argv)
{
	int			i;
	t_bilist	*slot_act;
	t_bilist	*next_slot;

	*slot_ini = bilst_new(NULL, ft_atoi(argv[1]));
	if (!slot_ini)
    {
        ft_printf("Error\nMemory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
	slot_act = *slot_ini;
	i = 2;
	while (argv[i])
	{
		next_slot = bilst_new(slot_act , ft_atoi(argv[i]));
		if (!next_slot)
        {
            ft_printf("Error\nMemory allocation failed.\n");
            free_slots(*slot_ini);
            exit(EXIT_FAILURE);
        }
		slot_act->next = next_slot;
		slot_act = next_slot;
		i++;
	}
}
