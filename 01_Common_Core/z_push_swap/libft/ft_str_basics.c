/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:23:51 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/11 22:24:58 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the number of characters in a string, excluding the null terminator.
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// Compares the first `n` characters of the strings `s1` and `s2`.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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

// Concatenates the strings `s1` and `s2` and returns a new string.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < (s1_len + s2_len))
	{
		if (i < s1_len)
			s3[i] = s1[i];
		else
			s3[i] = s2[i - s1_len];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
