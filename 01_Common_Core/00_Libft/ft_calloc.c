/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:28:49 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:09:37 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory for an array of nmemb elements, and initializes it to zero.

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;

	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}

/*
#include <unistd.h>
int	main (void)
{
	char	*arr;

	arr = ft_calloc(4, 6);
	if (arr[26] == 0)
		write(1, "a", 1);
	else
		write(1, "b", 1);
	return (0);
}
*/
