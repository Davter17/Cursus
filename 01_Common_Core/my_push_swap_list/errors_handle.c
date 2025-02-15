/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:29:12 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/14 02:47:36 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_only_numbers(char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (c != ' ' && c != '-' && (c < '0' || c > '9'))
				return (0);
			if (c == '-' && ((argv[i][j + 1] < '0' || argv[i][j + 1] > '9')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	check_int_limits(char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_repeated_numbers(int argc, char **argv)
{
	int	i;
	int	j;
	int	*str_int;

	str_int = malloc((argc + 1) * sizeof(int));
	if (!str_int)
		return (0);
	i = 0;
	while (argv[i + 1])
	{
		str_int[i] = ft_atoi(argv[i + 1]);
		j = 0;
		while (j != (i))
		{
			if (str_int[j] == str_int[i])
				return (free(str_int), 0);
			j++;
		}
		i++;
	}
	return (free(str_int), 1);
}

int	check_argv(int argc, char **argv)
{
	if (check_only_numbers(argv) == 0)
		return (0);
	if (check_int_limits(argv) == 0)
		return (0);
	if (check_repeated_numbers(argc, argv) == 0)
		return (0);
	return (1);
}
