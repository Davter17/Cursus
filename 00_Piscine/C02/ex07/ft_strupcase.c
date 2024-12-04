/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:40:47 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/13 19:11:17 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int		incremental;

	incremental = 0;
	while (str[incremental] != '\0')
	{
		if (str[incremental] >= 'a' && str[incremental] <= 'z')
		{
			str[incremental] -= 32;
		}
		incremental++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str[] = "Hola mundo.";
	int		incremental;

	incremental = 0;
	ft_strupcase(str);
	while (str[incremental] != '\0')
	{
		write(1, &str[incremental], 1);
		incremental++;
	}
}
*/
