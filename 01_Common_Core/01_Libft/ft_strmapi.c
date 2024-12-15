/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:23:26 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/15 20:23:26 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

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
