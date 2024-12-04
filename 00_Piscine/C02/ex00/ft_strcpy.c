/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:27:13 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/26 12:58:38 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		incremental++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
void	ft_print_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	char	*str_1;
	char	str_2[30];

	str_1 = "Hola mundo.";
	ft_print_str(str_1);
	ft_strcpy(str_2, str_1);
	ft_print_str(str_2);
	return (0);
}
*/
