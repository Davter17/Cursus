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

int	ft_atoi_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\v' || base[i] == '\f')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi_base_recursive(char *str, char *base, int base_len, int *i)
{
	int	result;
	int	digit;

	result = 0;
	while (str[*i] != '\0')
	{
		digit = 0;
		while (base[digit] != '\0')
		{
			if (str[*i] == base[digit])
				break ;
			digit++;
		}
		if (digit >= base_len)
			break ;
		result = result * base_len + digit;
		(*i)++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	i;
	int	sign;
	int	result;

	base_len = ft_atoi_base_check(base);
	if (base_len < 2)
		return (0);
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = ft_atoi_base_recursive(str, base, base_len, &i);
	return (result * sign);
}

/*
int	main(int argc, char **argv)
{
	int	number;

	if (argc > 2)
	{
		number = ft_atoi_base(argv[1], argv[2]);
		return (0);
	}
	return (0);
}
*/
