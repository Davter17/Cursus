/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_document.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:52:31 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/25 18:47:46 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define DICT_SIZE 1025

int		ft_strlen(char *str);
void	parse_key_value(char *buffer, char **dict, int *i, int *j);

// Opens a file in read-only mode and returns its file descriptor.
int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		write(1, "Dict Error\n", 11);
	return (fd);
}

// Reads the content of a file into a dynamically allocated buffer.
char	*read_file(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(DICT_SIZE);
	if (buffer == NULL)
	{
		write(1, "Error\n", 6);
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, buffer, DICT_SIZE - 1);
	close(fd);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

// Allocates memory for a dictionary of key-value pairs.
char	**allocate_dict(void)
{
	char	**dict;

	dict = malloc(100 * sizeof(char *));
	if (dict == NULL)
		write(1, "Error\n", 6);
	return (dict);
}

// Builds a dictionary from the buffer content.
char	**build_dict(char *buffer)
{
	char	**dict;
	int		i;
	int		j;

	dict = allocate_dict();
	if (dict == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i] != '\0')
		parse_key_value(buffer, dict, &i, &j);
	dict[j] = NULL;
	return (dict);
}

// Reads a document and parses it into a dictionary of key-value pairs.
char	**ft_read_document(char *file_name)
{
	int		fd;
	char	*buffer;
	char	**dict;

	fd = open_file(file_name);
	if (fd == -1)
		return (NULL);
	buffer = read_file(fd);
	if (buffer == NULL)
		return (NULL);
	dict = build_dict(buffer);
	free(buffer);
	return (dict);
}
