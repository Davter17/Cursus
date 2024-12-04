/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:03:52 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 15:40:40 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex_digits[(*str / 16)], 1);
			write(1, &hex_digits[(*str % 16)], 1);
		}
		str++;
	}
}

/*
int	main(void)
{
	char	*str;

	str = "Coucou\btu vas bien ?";
	ft_putstr_non_printable(str);
	return (0);
}
*/
