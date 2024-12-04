/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:48:54 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/14 18:36:42 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	incremental;

	incremental = 0;
	while (incremental < n)
	{
		if (s1[incremental] == '\0' && s2[incremental] == '\0')
			return (0);
		else if (s1[incremental] != s2[incremental])
			return (s1[incremental] - s2[incremental]);
		incremental++;
	}
	return (0);
}

/*
int	main(void)
{
	char	*str1;
	char	*str2;
	int		size;
	int		result;

	str1 = "Holabss";
	str2 = "Holaass";
	size = 6;
	result = ft_strncmp(str1, str2, size);
	if (result == 0)
		write(1, &"Las cadenas son iguales.", 24);
	else if (result < 0)
		write(1, &"La cadena str2 es mayor", 24);
	else
		write(1, &"La cadena str1 es mayor", 24);
	return (0);
}
*/