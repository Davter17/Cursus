/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/22 12:33:35 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_print_int(int i)
{
	int		len;

	len = 0;
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
		len++;
	}
	if (i >= 10)
		len += ft_print_int(i / 10);
	write(1, &"0123456789"[i % 10], 1);
	len++;
	return (len);
}

int	ft_print_unsigned(unsigned int u)
{
	int	len;

	len = 0;
	if (u >= 10)
		len += ft_print_unsigned(u / 10);
	write(1, &"0123456789"[u % 10], 1);
	len++;
	return (len);
}
