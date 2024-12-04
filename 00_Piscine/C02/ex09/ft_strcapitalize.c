/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:12:18 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 12:38:14 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	char	lst;

	lst = '\0';
	while (*str != '\0')
	{
		if ((lst >= 'a' && lst <= 'z') || (lst >= 'A' && lst <= 'Z')
			|| (lst >= '0' && lst <= '9'))
		{
			if (*str >= 'A' && *str <= 'Z')
				*str += 32;
		}
		else if ((lst == '\0' || !(lst >= 'a' && lst <= 'z'))
			&& !(lst >= 'A' && lst <= 'Z') && !(lst >= '0' && lst <= '9'))
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
		else
			lst = '\0';
		lst = *str;
		str++;
	}
	return (str - 1);
}

/*
int	main(void)
{
	char	str[] = "saLUt, coMMEnt tu vAs ? 42Mots quaRA-deux; cinQUAntE+et+Un";
	int		incremental;

	incremental = 0;
	while (str[incremental] != '\0')
	{
		write(1, &str[incremental], 1);
		incremental++;
	}
	write(1, &"\n", 1);
	incremental = 0;
	ft_strcapitalize(str);
	while (str[incremental] != '\0')
	{
		write(1, &str[incremental], 1);
		incremental++;
	}
	return (0);
}
*/
