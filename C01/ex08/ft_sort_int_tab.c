/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:23:46 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/11 10:42:58 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	counter;
	int	num_aux;

	counter = 0;
	num_aux = 0;
	while (counter < size - 1)
	{
		if (tab[counter] <= tab[counter + 1])
			counter++;
		else
		{
			num_aux = tab[counter];
			tab[counter] = tab[counter + 1];
			tab[counter + 1] = num_aux;
			counter = 0;
		}
	}
}

/*
int	main(void)
{
	int	tab[4];
	int	size;
	int	i;

	tab[0] = 6;
	tab[1] = 3;
	tab[2] = 6;
	tab[3] = -5;
	size = sizeof(tab) / sizeof(tab[0]);
	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/