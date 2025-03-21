/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:41:26 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/11 23:17:18 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(char const *str, ...);
int		ft_print_int(int i);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_unsigned(unsigned int u);
int		ft_print_adress(void *ptr);
int		ft_print_hex(int d, int type);

#endif