/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:18:01 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/20 13:30:57 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	counter;

	counter = 0;
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (counter < (max - min))
	{
		(*range)[counter] = min + counter;
		counter++;
	}
	return (counter);
}

/*
int	main(void)
{
	int	length;
	int	counter;
	int	*strint;

	length = ft_ultimate_range(&strint, 1, 10);
	counter = 0;
	while (counter < length)
	{
		write(1, &"0123456789"[strint[counter]], 1);
		counter++;
	}
	free(strint);
	return (0);
}
*/
