/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:14 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 02:43:46 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the character is a valid ASCII character (0-127).

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <unistd.h>

int main(void)
{
	int	numb;

	numb = ft_isascii('-');
	write(1, &"0123456789"[numb], 1);
	return (0);
}
*/