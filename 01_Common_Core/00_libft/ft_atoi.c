/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:20:49 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 02:32:22 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts the string `nptr` to an integer.

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
#include <unistd.h>

int main(void)
{
	const char	*nptr;
	int			number;

	nptr = "0";
	number = ft_atoi(nptr);
	write(1, &"0123456789"[number / 100 % 10], 1);
	write(1, &"0123456789"[number / 10 % 10], 1);
	write(1, &"0123456789"[number / 1 % 10], 1);
	return (1);
}
*/