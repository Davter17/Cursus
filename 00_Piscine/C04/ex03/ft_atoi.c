/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:08:52 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/18 13:51:45 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ptrnbr(int number)
{
	if (number < 0)
	{
		write (1, "-", 1);
		number *= -1;
	}
	if (number > 10)
	{
		ft_ptrnbr(number / 10);
	}
	write(1, &"0123456789"[number % 10], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	cnt_negative;
	int	number;

	i = 0;
	cnt_negative = 0;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cnt_negative++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (cnt_negative % 2 != 0)
		number *= -1;
	return (number);
}

/*
int	main(int argc, char **argv)
{
	int	number;

	if (argc > 0)
	{
		number = ft_atoi(argv[1]);
		ft_ptrnbr(number);
	}
	return (0);
}
*/
