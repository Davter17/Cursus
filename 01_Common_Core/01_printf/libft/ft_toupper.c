/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:08:55 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 02:53:01 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts a lowercase letter to uppercase.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
#include <unistd.h>

int main (void)
{
	int	cap;

	cap = ft_toupper('-');
	write(1, &cap, 1);
}
*/
