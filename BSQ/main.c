/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:23:24 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/27 17:40:02 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAP_SIZE 2048

int		process_map2(char *file_name);
int		allocate_resources(char **map, char **parameters, int **start);
int		read_and_validate_map(char *file_name, char *map);
int		process_matrix(char *map, char **parameters, int **start);
void	free_resources1(char *map, int *mat_size, char **matrix);
void	free_resources2(char *parameters, int *start);

char	*ft_read_document(char *map_name, char *map);
char	**ft_fill_square(char **matrix, int *start, char *parameters);
void	ft_print_matrix(char **matrix, int *mat_size);
char	**ft_map_to_matrix(char *map, int *mat_size);
int		*ft_matrix_size(char *map);
int		*ft_solve_square(char **matrix, int *start, int *mat_size,
			char *parameters);
char	*ft_read_parameters(char *map, char *parameters);

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			if (!process_map2(argv[i]))
				write(1, "map error\n\n", 11);
			i++;
		}
	}
	return (0);
}

int	allocate_resources(char **map, char **parameters, int **start)
{
	*map = malloc(MAP_SIZE * sizeof(char));
	*parameters = malloc(3 * sizeof(char));
	*start = malloc(3 * sizeof(int));
	if (!(*map) || !(*parameters) || !(*start))
	{
		if (*map != 0)
			free(*map);
		if (*parameters != 0)
			free(*parameters);
		if (*start != 0)
			free(*start);
		return (0);
	}
	(*start)[0] = 0;
	(*start)[1] = 0;
	(*start)[2] = 0;
	return (1);
}

char	**ft_fill_square(char **matrix, int *start, char *parameters)
{
	int	i;
	int	j;

	i = start[0];
	j = start[1];
	while (i < start[0] + start[2])
	{
		while (j < start[1] + start[2])
		{
			matrix[i][j] = parameters[2];
			j++;
		}
		i++;
		j = start[1];
	}
	return (matrix);
}

char	*ft_read_parameters(char *map, char *parameters)
{
	int	len;
	int	i;

	len = 0;
	while (map[len] && map[len] != '\n')
		len++;
	if (len < 3)
		return (NULL);
	i = len - 3;
	parameters[0] = map[i];
	parameters[1] = map[i + 1];
	parameters[2] = map[i + 2];
	if (parameters[0] == parameters[1] || parameters[0] == parameters[2]
		|| parameters[1] == parameters[2])
		return (NULL);
	return (parameters);
}

void	ft_print_matrix(char **matrix, int *mat_size)
{
	int	i;

	i = 0;
	while (i < mat_size[0])
	{
		write(1, matrix[i], mat_size[1]);
		write(1, "\n", 1);
		++i;
	}
}
