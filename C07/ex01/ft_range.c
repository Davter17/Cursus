/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:48:05 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/22 12:00:29 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*numbers;
	int	counter;

	counter = 0;
	if (min >= max)
		return (0);
	numbers = malloc((max - min) * sizeof(int));
	if (numbers == NULL)
		return (NULL);
	while (min < max)
	{
		numbers[counter] = min;
		min++;
		counter++;
	}
	return (numbers);
}

/*
int	main(int argc, char **argv)
{
	int	*numbers;

	if (argc > 2)
		numbers = ft_range(20, 30);
	return (0);
}
*/
