/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:13:33 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/04 21:13:33 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;
	size_t	i;

	needle_len = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (needle[needle_len] != '\0')
		needle_len++;
	if (needle_len > n)
		return (NULL);
	while (*haystack && n >= needle_len)
	{
		i = 0;
		while (haystack[i] == needle[i] && i < needle_len)
			i++;
		if (i == needle_len)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
