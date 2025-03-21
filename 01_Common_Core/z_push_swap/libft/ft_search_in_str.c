/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_in_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:23:37 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/11 19:32:21 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to the first character `c` in the string `s`.
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (NULL);
}

// Returns a pointer to the last character `c` in the string `s`.
char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			last = s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

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
