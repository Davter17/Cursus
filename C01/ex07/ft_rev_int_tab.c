/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:35:31 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/13 19:52:07 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	counter;
	int	num_aux;

	counter = 0;
	while (counter < size / 2)
	{
		num_aux = tab[counter];
		tab[counter] = tab[size - 1 - counter];
		tab[size - 1 - counter] = num_aux;
		counter++;
	}
}

/*
int main()
{
    int array[] = {1, -2, 3, 0};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array antes de revertir: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    ft_rev_int_tab(array, size);

    printf("Array después de revertir: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

	return (0);
}
*/
