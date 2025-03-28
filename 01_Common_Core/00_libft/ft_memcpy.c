/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:19:14 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:08:02 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies `n` bytes from the `src` memory block to the `dest` memory block.

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_2;
	const unsigned char	*src_2;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dest_2 = (unsigned char *)dest;
	src_2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_2[i] = src_2[i];
		i++;
	}
	return (dest);
}

/*
int main(void)
{
	void		*dest;
	const void	*src;
	size_t		n;
	
	src = "hello world";
	dest = malloc(1024);
	n = 1;
	dest = ft_memcpy(dest, src, n);
	write(1, dest, 20);
	return (0);
}
*/