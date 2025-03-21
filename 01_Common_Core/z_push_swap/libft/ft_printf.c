/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:06:05 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/10 02:57:48 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(const char *str, va_list args)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_print_char((char)va_arg(args, int));
	else if (*str == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (*str == 'p')
		len += ft_print_adress(va_arg(args, void *));
	else if (*str == 'i' || *str == 'd')
		len += ft_print_int(va_arg(args, int));
	else if (*str == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x')
		len += ft_print_hex(va_arg(args, int), 0);
	else if (*str == 'X')
		len += ft_print_hex(va_arg(args, int), 1);
	else if (*str == '%')
		len += ft_print_char('%');
	else
		len += ft_print_char(*str);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_handle_format(str, args);
		}
		else
			len += ft_print_char(str[0]);
		str++;
	}
	va_end(args);
	return (len);
}
