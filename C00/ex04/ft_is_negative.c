/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:15:50 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/07 19:18:31 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int positive_negative)
{
	char	letter;

	if (positive_negative >= 0)
	{
		letter = 'P';
	}
	else
	{
		letter = 'N';
	}
	write(1, &letter, 1);
	return ;
}

/*
int	main(void)
{
	int	number;

	number = 3;
	ft_is_negative(number);
	return (0);
}
*/