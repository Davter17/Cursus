/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:44:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/19 18:44:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (c == 'c' || c == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			total_len += ft_handle_conversion(format[++i], args);
		else
		{
			write(1, &format[i], 1);
			total_len++;
		}
		i++;
	}
	va_end(args);
	return (total_len);
}
