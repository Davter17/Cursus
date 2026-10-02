/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:52:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/26 13:32:01 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_base_check(char *base)
{
	int	counter;
	int	counter_back;

	counter = 0;
	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[counter] != '\0')
	{
		if (base[counter] == '+' || base[counter] == '-')
			return (0);
		counter_back = 0;
		while (counter_back < counter)
		{
			if (base[counter] == base[counter_back])
				return (0);
			counter_back++;
		}
		counter++;
	}
	return (counter);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	counter;

	counter = ft_putnbr_base_check(base);
	if (counter < 2)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(-(nbr / counter), base);
		write(1, &base[-(nbr % counter)], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= counter)
		ft_putnbr_base(nbr / counter, base);
	write(1, &base[nbr % counter], 1);
}

/*
int main(int argc, char **argv)
{
	if (argc > 1)
		ft_putnbr_base(20, argv[2]);
}
*/
