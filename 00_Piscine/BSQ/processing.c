/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:41:14 by trsilva-          #+#    #+#             */
/*   Updated: 2024/11/27 17:42:02 by trsilva-         ###   ########.fr       */
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

char	*ft_read_document(char *map_name, char *map)
{
	int	fd;
	int	bytes_read;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	bytes_read = read(fd, map, MAP_SIZE - 1);
	close(fd);
	if (bytes_read <= 0)
		return (NULL);
	map[bytes_read] = '\0';
	return (map);
}

int	read_and_validate_map(char *file_name, char *map)
{
	if (!ft_read_document(file_name, map))
		return (0);
	return (1);
}

int	process_map2(char *file_name)
{
	char	*map;
	char	*parameters;
	int		*start;

	if (!allocate_resources(&map, &parameters, &start))
		return (0);
	if (!read_and_validate_map(file_name, map))
	{
		free_resources2(parameters, start);
		return (0);
	}
	if (!process_matrix(map, &parameters, &start))
	{
		free_resources2(parameters, start);
		return (0);
	}
	free_resources2(parameters, start);
	return (1);
}

int	process_matrix(char *map, char **parameters, int **start)
{
	int		*mat_size;
	char	**matrix;

	mat_size = ft_matrix_size(map);
	if (!mat_size)
		return (0);
	matrix = ft_map_to_matrix(map, mat_size);
	if (!matrix)
	{
		free(mat_size);
		return (0);
	}
	if (!ft_read_parameters(map, *parameters))
	{
		free(mat_size);
		free_resources1(NULL, mat_size, matrix);
		free_resources2(*parameters, *start);
		return (0);
	}
	*start = ft_solve_square(matrix, *start, mat_size, *parameters);
	matrix = ft_fill_square(matrix, *start, *parameters);
	ft_print_matrix(matrix, mat_size);
	free_resources1(NULL, mat_size, matrix);
	free_resources2(*parameters, *start);
	return (1);
}
