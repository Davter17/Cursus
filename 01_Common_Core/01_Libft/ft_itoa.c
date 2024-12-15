/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:47:06 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/06 21:47:06 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

#include <stdlib.h>

#include <stdlib.h>

char *ft_itoa(int n)
{
    char *str;
    int len;
    int tmp_n;
    int sign;

    tmp_n = n;
    len = 0;
    if (tmp_n == 0)
        len = 1;
    else if (tmp_n < 0)
    {
        len = 2;
        tmp_n = -tmp_n;
    }
    while (tmp_n != 0)
    {
        tmp_n = tmp_n / 10;
        len++;
    }
    str = (char *)malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    if (n == 0)
    {
        str[0] = '0';
        return str;
    }
    sign = (n < 0) ? -1 : 1;
    if (sign == -1)
    {
        str[0] = '-';
        n = -n;
    }
    while (n != 0)
    {
        len--;
        str[len] = (n % 10) + '0';
        n = n / 10;
    }
    return (str);
}
