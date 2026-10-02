/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:17:31 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/13 19:11:10 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
			str++;
		else
			return (0);
	}
	return (1);
}

/*
int	main(void)
{
	char	*str;
	int		alphanumeric;

	str = "grgrger\agergerger";
	alphanumeric = 4;
	alphanumeric = ft_str_is_printable(str);
	write(1, &"0123456789"[alphanumeric], 1);
	return (0);
}
*/