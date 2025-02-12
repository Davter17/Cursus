/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:11 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/12 11:44:42 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct bi_s_list
{
	struct bi_s_list	*pre;
	int				content;
	struct bi_s_list	*next;
}	bi_t_list;

int			generate_slot(bi_t_list **slot_ini, int size, char **argv);
int			check_argv(char **argv);

void		sa(bi_t_list *slot);
void		sb(bi_t_list *slot);
void		ss(bi_t_list *slot_a, bi_t_list *slot_b);
void		pa(bi_t_list **slot_a, bi_t_list **slot_b);
void		pb(bi_t_list **slot_a, bi_t_list **slot_b);
void		ra(bi_t_list *slot);
void		rb(bi_t_list *slot);
void		rr(bi_t_list *slot_a, bi_t_list *slot_b);
void		rra(bi_t_list *slot);
void		rrb(bi_t_list *slot);
void		rrr(bi_t_list *slot_a, bi_t_list *slot_b);

bi_t_list	*bilst_new(bi_t_list *prev, int content);
int			bilst_size(bi_t_list *lst);
bi_t_list	*bilst_last(bi_t_list *lst);
void		bilst_print(bi_t_list *head);

void		solve_list(bi_t_list *slot_a, bi_t_list *slot_b);

#endif
