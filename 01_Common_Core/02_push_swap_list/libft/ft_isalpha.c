/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:14:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 02:53:18 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the given character is an alphabet letter.

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

/*
#include <unistd.h>

int main(void)
{
	int	numb;

	numb = ft_isalpha('a');
	write(1, &"0123456789"[numb], 1);
	return (0);
}
*/
