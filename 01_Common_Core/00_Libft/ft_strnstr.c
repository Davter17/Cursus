/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:13:33 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:22:59 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"

// Finds the first string `little` in the `big`, limited to `n` characters.

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0)
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (i + j < len && little[j] != '\0' && big [i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
	const char	*big;
	const char	*little;
	char		*dup;

	big = "hello wo";
	little = "ll";
	dup = ft_strnstr(big, little, 16);
	write(1, dup, 16);
	return (0);
}

*/