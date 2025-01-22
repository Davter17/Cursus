/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:09:23 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/20 19:35:58 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
int main(void)
{
	const void	*s1;
	const void	*s2;
	int			numb;
	size_t		n;
	
	s1 = "helle world";
	s2 = "hella world";
	n = 7;
	numb = ft_memcmp(s1, s2, n);
	write(1, &"0123456789"[numb], 1);
	return (0);
}
*/