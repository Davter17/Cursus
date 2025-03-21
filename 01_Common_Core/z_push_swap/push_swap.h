/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:11 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/18 21:56:16 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_bilist
{
	struct s_bilist	*prev;
	int				value;
	struct s_bilist	*next;
	int				index;
	int				push_cost;
	int				upper;
	int				cheapest;
	struct s_bilist	*target;
}	t_bilist;

//Algorithms
void		sa(t_bilist **slot);
void		sb(t_bilist **slot);
void		ss(t_bilist **slot_a, t_bilist **slot_b);

void		pa(t_bilist **slot_a, t_bilist **slot_b);
void		pb(t_bilist **slot_a, t_bilist **slot_b);

void		ra(t_bilist **slot);
void		rb(t_bilist **slot);
void		rr(t_bilist **slot_a, t_bilist **slot_b);

void		rra(t_bilist **slot);
void		rrb(t_bilist **slot);
void		rrr(t_bilist **slot_a, t_bilist **slot_b);

//Slot utils
void	generate_slot(t_bilist **slot_ini, char **argv);

int			slot_sorted(t_bilist *slot);
int			slot_len(t_bilist *slot);
t_bilist	*slot_min(t_bilist *slot);
t_bilist	*slot_max(t_bilist *slot);
t_bilist	*slot_last(t_bilist *slot);
void		slot_print(t_bilist *slot);

#endif