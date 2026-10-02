/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:37:41 by trsilva-          #+#    #+#             */
/*   Updated: 2024/11/27 17:43:15 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAP_SIZE 2048

void	free_resources1(char *map, int *mat_size, char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
	if (mat_size)
		free(mat_size);
	if (map)
		free(map);
}

void	free_resources2(char *parameters, int *start)
{
	if (parameters)
		free(parameters);
	if (start)
		free(start);
}
