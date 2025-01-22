/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:09:28 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:09:27 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sets `n` bytes of memory to zero.

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*
#include <unistd.h>

int main(void)
{
	char	*s;

	s = malloc(5 * sizeof(char));
	s[0] = 'a';
	s[1] = 'b';
	s[2] = 'c';
	s[3] = 'd';
	s[4] = '\0';
	write(1, s, 5);
	write(1, "\n", 1);
	ft_bzero(s, 5);
	write(1, s, 5);
	write(1, "\n", 1);
}
*/
