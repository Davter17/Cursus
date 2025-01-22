/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:17:24 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:13:14 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Fills a block of memory with the byte `c` for `n` bytes.

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i++;
	}
	return (s);
}

/*
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
	ft_memset(s, 'a' ,5);
	write(1, s, 5);
	write(1, "\n", 1);
}
*/
