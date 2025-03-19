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

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_bilist
{
	int				value;
	int				index;
	int				push_cost;
	bool			upper;
	bool			cheapest;
	struct s_bilist	*target;
	struct s_bilist	*next;
	struct s_bilist	*prev;
}	t_bilist;


#endif