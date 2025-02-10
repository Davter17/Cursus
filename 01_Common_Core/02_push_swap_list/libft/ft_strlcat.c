/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:55:01 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 12:13:52 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Appends `src` to the end of `dst`. ensuring the total length does not exceed.

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	i = 0;
	if (dsize <= dst_len)
		return (src_len + dsize);
	while (src[i] && (dst_len + i) < (dsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
int main(void)
{
	const char	*s1;
	char		*dup;
	size_t		size;

	s1 = "hello world";
	dup = malloc(1024);
	size = ft_strlcat(dup, s1, 12);
	write(1, dup, 12);
	write(1, "\n", 1);
	write(1, &"0123456789"[(int)size], 1);
	return (0);
}
*/
