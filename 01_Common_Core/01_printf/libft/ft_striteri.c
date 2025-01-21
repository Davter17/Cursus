/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:01:27 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 17:01:28 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
void ft_toupper_iter(unsigned int i, char *c)
{
	(void)i;
    *c = ft_toupper(*c);
}

int main(void)
{
	char	*s;

	s = malloc(1024);
	s[0] = 'h';
	s[1] = 'e';
	s[2] = 'l';
	s[3] = 'l';
	ft_striteri(s, ft_toupper_iter);
	write(1, s, 5);
	return (0);	
}
*/