/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:43:39 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 12:27:54 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// Copies a string from `src` to `dst`, ensuring the destination is not overrun.

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < (dsize - 1) && dsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dsize > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
