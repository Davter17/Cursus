/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:05:41 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/11 19:32:12 by mpico-bu         ###   ########.fr       */
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

// Compares the first `n` bytes of memory blocks `s1` and `s2`.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}
