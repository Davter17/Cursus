/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:11 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 16:08:30 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_bilist
{
	struct s_bilist	*pre;
	int				content;
	struct s_bilist	*next;
}	t_bilist;

int			generate_slot(t_bilist **slot_ini, int size, char **argv);
int			check_argv(int argc, char **argv);

void		sa(t_bilist *slot);
void		sb(t_bilist *slot);
void		ss(t_bilist *slot_a, t_bilist *slot_b);
void		pa(t_bilist **slot_a, t_bilist **slot_b);
void		pb(t_bilist **slot_a, t_bilist **slot_b);
void		ra(t_bilist *slot);
void		rb(t_bilist *slot);
void		rr(t_bilist *slot_a, t_bilist *slot_b);
void		rra(t_bilist *slot);
void		rrb(t_bilist *slot);
void		rrr(t_bilist *slot_a, t_bilist *slot_b);

t_bilist	*bilst_new(t_bilist *prev, int content);
int			bilst_size(t_bilist *lst);
t_bilist	*bilst_last(t_bilist *lst);
void		bilst_print(t_bilist *head);

void		solve_list(t_bilist *slot_a, t_bilist *slot_b);

#endif
