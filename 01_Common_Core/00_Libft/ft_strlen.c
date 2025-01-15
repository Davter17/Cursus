/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:59 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:19:46 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the number of characters in a string, excluding the null terminator.

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
int main(void)
{
	const char	*s;
	size_t		n;

	s = "hello";
	n = ft_strlen(s);
	write(1, &"0123456789"[n], 1);
	return (0);
}
*/