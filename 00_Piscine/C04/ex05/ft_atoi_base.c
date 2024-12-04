/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:12:48 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/17 21:22:12 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_base_check(char *base)
{
	int	counter;
	int	counter_back;

	counter = 0;
	counter_back = 0;
	while (base[counter] != '\0')
	{
		if (base[counter] == '+' || base[counter] == '-')
			return (0);
		while (counter_back < counter)
		{
			if (base[counter] == base[counter_back])
				return (0);
			counter_back++;
		}
		counter_back = 0;
		counter++;
	}
	return (counter);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	counter;

	counter = ft_putnbr_base_check(base);
	number = 0;
	if (counter < 2)
		return (0);
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= counter)
		ft_putnbr_base(nbr / counter, base);
	return (nbr);
}

int	ft_atoi(char *str)
{
	int	incremental;
	int	cnt_negative;
	int	number;

	incremental = 0;
	cnt_negative = 0;
	number = 0;
	while (str[incremental] == ' ')
		incremental++;
	if (str[incremental] == '-')
	{
		cnt_negative++;
		incremental++;
	}
	while (str[incremental] >= '0' && str[incremental] <= '9')
	{
		number = number * 10 + (str[incremental] - '0');
		incremental++;
	}
	if (cnt_negative % 2 != 0)
		number *= -1;
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	number;

	number = ft_atoi(str);
	number = ft_putnbr_base(number, base);
	return (number);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 10)
	{
		ft_putnbr(nb / 10);
	}
	write(1, &"0123456789"[nb % 10], 1);
}

/*
int	main(int argc, char **argv)
{
	int	number;
	
	if (argc > 2)
	{
		number = ft_atoi_base(argv[1], argv[2]);
		ft_putnbr(number);
	}
}
*/
