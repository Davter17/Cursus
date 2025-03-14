/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:27:21 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:08:54 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copies `n` bytes from the `src` to the `dest`, handling overlapping.

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_2;
	const unsigned char	*src_2;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dest_2 = (unsigned char *)dest;
	src_2 = (const unsigned char *)src;
	if (dest_2 < src_2)
	{
		i = 0;
		while (i < n)
		{
			dest_2[i] = src_2[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			dest_2[i] = src_2[i];
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
	dest = ft_memmove(dest, src, n);
	write(1, dest, 20);
	return (0);
}
*/