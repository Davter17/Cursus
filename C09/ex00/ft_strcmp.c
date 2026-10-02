/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:41:36 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/14 04:55:18 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

/*
int	main(void)
{
	char	*str1;
	char	*str2;
	int		result;

	str1 = "Holas";
	str2 = "Holas";
	result = ft_strcmp(str1, str2);
	if (result == 0)
		write(1, &"Las cadenas son iguales.", 24);
	else if (result < 0)
		write(1, &"La cadena str2 es mayor.", 24);
	else
		write(1, &"La cadena str1 es mayor.", 24);
	return (0);
}
*/
