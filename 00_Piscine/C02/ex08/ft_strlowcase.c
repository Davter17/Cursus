/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:17 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/12 11:11:02 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	incremental;

	incremental = 0;
	while (str[incremental] != '\0')
	{
		if (str[incremental] >= 'A' && str[incremental] <= 'Z')
			str[incremental] += 32;
		incremental++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str[] = "hOLA munDo!";
	int		incremental;

	incremental = 0;
	ft_strlowcase(str);
	while (str[incremental] != '\0')
	{
		write(1, &str[incremental], 1);
		incremental++;
	}
}
*/
