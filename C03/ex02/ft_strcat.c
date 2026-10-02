/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:05:09 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/14 04:55:29 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	incremental_dest;
	int	incremental_src;

	incremental_dest = 0;
	incremental_src = 0;
	while (dest[incremental_dest] != '\0')
		incremental_dest++;
	while (src[incremental_src] != '\0')
	{
		dest[incremental_dest] = src[incremental_src];
		incremental_dest++;
		incremental_src++;
	}
	dest[incremental_dest] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char	str1[30];
	char	*str2;
	int		incremental;

	str1[0] = 'H';
	str1[1] = 'o';
	str1[2] = 'l';
	str1[3] = 'a';
	str1[4] = ' ';
	str2 = "caracola";
	incremental = 0;
	ft_strcat(str1, str2);
	while (str1[incremental] != '\0')
	{
		write(1, &str1[incremental], 1);
		incremental++;
	}
	return (0);
}
*/
