/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:56:18 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/15 01:13:29 by mpico-bu         ###   ########.fr       */
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
	char	*string;
	int		result;

	string = "holcszczsczsczssczsczsczsczsai";
	result = 4;
	result = ft_strlen(string);
	write(1, &"0123456789"[result / 10], 1);
	write(1, &"0123456789"[result % 10], 1);
	return (0);
}
*/
