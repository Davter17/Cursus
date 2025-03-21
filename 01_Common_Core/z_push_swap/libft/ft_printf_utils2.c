/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:38:58 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/22 12:29:03 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(int d, int type)
{
	unsigned int	num;
	char			*hex;
	int				len;

	num = (unsigned int)d;
	if (type == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	len = 0;
	if (num >= 16)
		len += ft_print_hex(num / 16, type);
	write(1, &hex[num % 16], 1);
	len++;
	return (len);
}

int	ft_print_unsigned_hex(uintptr_t u)
{
	int	len;

	len = 0;
	if (u >= 16)
		len += ft_print_unsigned_hex(u / 16);
	write(1, &"0123456789abcdef"[u % 16], 1);
	len++;
	return (len);
}

int	ft_print_adress(void *ptr)
{
	uintptr_t	address;
	int			len;

	address = (uintptr_t)ptr;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = ft_print_unsigned_hex(address) + 2;
	return (len);
}
