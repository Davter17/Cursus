/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:52:07 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/22 11:28:45 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	incremental;

	incremental = 0;
	while (incremental < n && src[incremental] != '\0')
	{
		dest[incremental] = src[incremental];
		incremental++;
	}
	while (incremental < n)
	{
		dest[incremental] = '\0';
		incremental++;
	}
	return (dest);
}

/*
void	ft_printstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	char	*str;
	char	str2[30];

	str = "Hola mundo.";
	ft_strncpy(str2, str, 20);
	ft_printstr(str2);
	return (0);
}
*/
