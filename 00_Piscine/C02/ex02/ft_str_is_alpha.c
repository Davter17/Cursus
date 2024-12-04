/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:17:31 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/11 20:38:25 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	char	*an_str;
	int		incremental;

	incremental = 0;
	an_str = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
	if (an_str[incremental] == '\0')
		return (1);
	while (*str != '\0')
	{
		while (an_str[incremental] != '\0')
		{
			if (*str == an_str[incremental])
			{
				incremental = 0;
				str++;
				break ;
			}
			else
				incremental++;
		}
		if (an_str[incremental] == '\0')
			return (0);
	}
	return (1);
}

/*
int	main(void)
{
	char	*str;
	int		alphanumeric;

	str = "T0nt04.";
	alphanumeric = 4;
	alphanumeric = ft_str_is_alpha(str);
	write(1, &"0123456789"[alphanumeric], 1);
	return (0);
}
*/
