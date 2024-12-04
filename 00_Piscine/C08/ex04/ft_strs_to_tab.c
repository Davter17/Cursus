/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:45:42 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/28 15:50:15 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free_all(int i, t_stock_str *arr)
{
	while (i >= 0)
	{
		free(arr[i].copy);
		i--;
	}
	free(arr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = malloc((arr[i].size + 1) * sizeof(char));
		if (!arr[i].copy)
		{
			ft_free_all(i, arr);
			return (NULL);
		}
		ft_strcpy(arr[i].copy, av[i]);
		i++;
	}
	arr[i].str = NULL;
	return (arr);
}

/*
int	main(int argc, char **argv)
{
	t_stock_str	*arr;

	arr = ft_strs_to_tab(argc, argv++);
	ft_show_tab(arr);
	return (0);
}
*/
