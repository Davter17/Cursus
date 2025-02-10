/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:11 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/10 01:21:40 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*pre;
	int				content;
	struct s_list	*next;
}	t_list;

void	sa(t_list *slot);
void	sb(t_list *slot);
void	ss(t_list *slot_a, t_list *slot_b);
void	pa(t_list **slot_a, t_list **slot_b);
void	pb(t_list **slot_a, t_list **slot_b);
void	ra(t_list *slot);
void	rb(t_list *slot);
void	rr(t_list *slot_a, t_list *slot_b);
void	rra(t_list *slot);
void	rrb(t_list *slot);
void	rrr(t_list *slot_a, t_list *slot_b);

#endif
