/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:27:21 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/04 18:27:21 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_2;
	const unsigned char	*src_2;
	size_t				i;

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
		while (i > 0)
		{
			i--;
			dest_2[i] = src_2[i];
		}
	}
	return (dest);
}
