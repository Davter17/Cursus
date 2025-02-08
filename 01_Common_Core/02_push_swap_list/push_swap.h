/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:11 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 19:46:23 by mpico-bu         ###   ########.fr       */
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
	int             content;
	struct s_list	*next;
}	t_list;

void	sa(int *slot);
void	sb(int *slot);
void	ss(int *slot_a, int *slot_b);
void	pa(int *slot_a, int *slot_b);
void	pb(int *slot_a, int *slot_b);
void	ra(int *slot);
void	rb(int *slot);
void	rr(int *slot_a, int *slot_b);
void	rra(int *slot);
void	rrb(int *slot);
void	rrr(int *slot_a, int *slot_b);

int	    ft_atoi(const char *nptr);

#endif
