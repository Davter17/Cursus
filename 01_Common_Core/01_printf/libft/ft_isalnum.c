/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:14:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 02:43:01 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the given character is either a letter or a digit.

int	ft_isalnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <unistd.h>

int main(void)
{
	int	numb;

	numb = ft_isalnum('-');
	write(1, &"0123456789"[numb], 1);
	return (0);
}
*/