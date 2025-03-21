/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr_modify.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:19:29 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/11 22:20:46 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts an uppercase letter to lowercase.
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// Converts a lowercase letter to uppercase.
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// Applies  `f` to each character of `s`, passing its index as an argument.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// Applies `f` to each character of `s` and returns a new string.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;
	unsigned int	len;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
