/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:05:16 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:01:30 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Searches for the first occurrence of the byte `c` in the memory block `s`.

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		if (ptr[0] == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	const void	*s;
	void		*sub_s;
	int			c;
	size_t		n;
	
	s = "hello world";
	c = 'l';
	n = 5;
	sub_s = ft_memchr(s, c, n);
	write(1, sub_s, 2);
	return (0);
}
*/