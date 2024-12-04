/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:54:42 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/14 18:41:50 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i_dest;
	unsigned int	i_src;

	i_dest = 0;
	i_src = 0;
	while (dest[i_dest] != '\0')
		i_dest++;
	while (src[i_src] != '\0' && i_dest < size -1)
	{
		dest[i_dest] = src[i_src];
		i_src++;
		i_dest++;
	}
	dest[i_dest] = '\0';
	return (*dest);
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
	ft_strlcat(str1, str2, 30);
	while (str1[incremental] != '\0')
	{
		write(1, &str1[incremental], 1);
		incremental++;
	}
	return (0);
}
*/