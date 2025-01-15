/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:09:23 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:05:23 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares the first `n` bytes of memory blocks `s1` and `s2`.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
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