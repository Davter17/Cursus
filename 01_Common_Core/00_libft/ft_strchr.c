/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:14:48 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/05 12:28:40 by mpico-bu         ###   ########.fr       */
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

/*
#include <unistd.h>

int main(void)
{
	const char	*s;
	char		*new;

	s = "hello world";
	new =  ft_strchr(s, 'l');
	write(1, new, 2);
	return (0);
}
*/