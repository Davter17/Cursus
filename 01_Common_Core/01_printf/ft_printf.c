/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:06:05 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/21 16:17:02 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_handle_format(const char **str, va_list args)
{
	int	result;

	result = 0;
	if (**str == 'c')
		result += ft_print_char((char)va_arg(args, int));
	else if (**str == 's')
		result += ft_print_str(va_arg(args, char *));
	else if (**str == 'p')
		result += ft_print_adress(va_arg(args, void *));
	else if (**str == 'i' || **str == 'd')
		result += ft_print_int(va_arg(args, int));
	else if (**str == 'u')
		result += ft_print_unsigned(va_arg(args, unsigned int));
	else if (**str == 'x')
		result += ft_print_hex(va_arg(args, int), 0);
	else if (**str == 'X')
		result += ft_print_hex(va_arg(args, int), 1);
	else if (**str == '%')
		result += ft_print_char('%');
	else
		result += ft_print_char(**str);
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		result;

	result = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			result += ft_handle_format(&str, args);
		}
		else
			result += ft_print_char(str[0]);
		str++;
	}
	va_end(args);
	return (result);
}

/*
int	main(void)
{
	int result;
	int *ptr;

	ptr = NULL;
	result = ft_printf(" %p", NULL);
	printf("\n%i", result);
	return (0);
}
*/