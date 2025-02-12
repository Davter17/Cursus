/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:29:12 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/11 18:43:31 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_argv(char **argv)
{
	int     i;
	int     j;
	char    c;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			c = argv[i][j];
			if (c != ' ' && c != '-' && (c <= '0' || c >= '9'))
			{				
				printf("Error\nOnly numbers accepted");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}