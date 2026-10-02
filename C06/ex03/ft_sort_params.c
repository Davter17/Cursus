/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:44:16 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/24 16:30:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_prt_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_sort_params(char **str)
{
	int		i;
	char	*aux;

	i = 1;
	while (str[i])
	{
		if (ft_strcmp(str[i], str[i - 1]) < 0)
		{
			aux = str[i];
			str[i] = str[i - 1];
			str[i - 1] = aux;
			i = 1;
		}
		else
			i++;
	}
	i = 1;
	while (str[i])
	{
		ft_prt_str(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_sort_params(argv);
	return (0);
}
