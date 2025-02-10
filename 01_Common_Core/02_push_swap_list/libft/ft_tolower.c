/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:08:55 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 02:52:57 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts an uppercase letter to lowercase.

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
#include <unistd.h>

int main (void)
{
	int	cap;

	cap = ft_tolower('-');
	write(1, &cap, 1);
}
*/
