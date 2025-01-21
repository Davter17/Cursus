/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/21 16:41:18 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_adress(void *ptr)
{
	uintptr_t	address;
	char		hex[16];
	char		*base;
	int			i;
	int			len;

	len = 2;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (uintptr_t)ptr;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	i = 0;
	while (address > 0)
	{
		hex[i++] = base[address % 16];
		address /= 16;
		len++;
	}
	while (--i >= 0)
		write(1, &hex[i], 1);
	return (len);
}

int	ft_print_int(int i)
{
	char	*str;
	size_t	len;

	str = ft_itoa(i);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return ((int)len);
}

int	ft_print_unsigned(unsigned int u)
{
	size_t	len;

	len = 0;
	if (u >= 10)
		len += ft_print_unsigned(u / 10);
	write(1, &"0123456789"[u % 10], 1);
	len++;
	return (len);
}

int	ft_print_hex(int d, int type)
{
	unsigned int	num;
	char			*hex;
	int				len;

	len = 0;
	num = (unsigned int)d;
	if (type == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num >= 16)
		len += ft_print_hex(num / 16, type);
	write(1, &hex[num % 16], 1);
	len++;
	return (len);
}
