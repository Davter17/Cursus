/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:29:23 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/11 10:36:14 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

/*
int	main(void)
{
	char	*pnt_str;
	int		length;

	pnt_str = "qwertyuiopasdfghjklzxcvbnm";
	length = ft_strlen(pnt_str);
	write(1, &"0123456789"[length / 10], 1);
	write(1, &"0123456789"[length % 10], 1);
	return (0);
}
*/
