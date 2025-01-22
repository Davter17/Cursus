/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:39 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:11:40 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the given character is a numerical digit.

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <unistd.h>

int main(void)
{
	int	numb;

	numb = ft_isdigit('-');
	write(1, &"0123456789"[numb], 1);
	return (0);
}
*/
