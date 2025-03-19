/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:11 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/16 05:50:10 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				position;
	int				cost;
	bool			cheapest;
	bool			ra;
	
	struct s_node	*pre;
	struct s_node	*next;
	struct s_node	*first_node;
}	t_node;

int			generate_slot(t_node **slot_ini, int size, char **argv);
int			check_argv(int argc, char **argv);

void		sa(t_node *slot);
void		sb(t_node *slot);
void		ss(t_node *slot_a, t_node *slot_b);
void		pa(t_node **slot_a, t_node **slot_b);
void		pb(t_node **slot_a, t_node **slot_b);
void		ra(t_node *slot);
void		rb(t_node *slot);
void		rr(t_node *slot_a, t_node *slot_b);
void		rra(t_node *slot);
void		rrb(t_node *slot);
void		rrr(t_node *slot_a, t_node *slot_b);

t_node	*bilst_new(t_node *prev, int content);
int			bilst_size(t_node *lst);
t_node	*bilst_last(t_node *lst);
int			bilst_min(t_node *lst);
int			bilst_max(t_node *lst);
void		bilst_print(t_node *head);

void 		solve_list(t_node **slot_a, t_node **slot_b);

#endif
