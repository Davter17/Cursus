/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:10:14 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/26 20:11:19 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

int	*initialize_size(void)
{
	int	*size;

	size = malloc(2 * sizeof(int));
	if (!size)
		return (NULL);
	size[0] = 0;
	size[1] = 0;
	return (size);
}

int	update_header_and_row(char current, int *row_length, int *in_header)
{
	if (*in_header)
	{
		if (current == '\n')
			*in_header = 0;
	}
	else
	{
		if (current != '\n')
			(*row_length)++;
		else
			return (1);
	}
	return (0);
}

int	validate_row_length(int *size, int *row_length)
{
	if (*row_length == 0)
		return (0);
	if (size[1] == 0)
		size[1] = *row_length;
	else if (size[1] != *row_length)
		return (0);
	size[0]++;
	*row_length = 0;
	return (1);
}

int	process_map(char *map, int *size)
{
	int	counter;
	int	row_length;
	int	in_header;

	counter = 0;
	row_length = 0;
	in_header = 1;
	while (map[counter])
	{
		if (update_header_and_row(map[counter], &row_length, &in_header))
		{
			if (!validate_row_length(size, &row_length))
				return (0);
		}
		counter++;
	}
	if (row_length > 0 && !validate_row_length(size, &row_length))
		return (0);
	return (1);
}

int	*ft_matrix_size(char *map)
{
	int	*size;

	size = initialize_size();
	if (!size)
		return (NULL);
	if (!process_map(map, size))
	{
		free(size);
		return (NULL);
	}
	return (size);
}
