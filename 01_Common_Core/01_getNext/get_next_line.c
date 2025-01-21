/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:40 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/19 11:29:23 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_bytes_read(ssize_t bytes_read, int i, char *buffer)
{
	if (bytes_read < 0 || (bytes_read == 0 && i == 0))
	{
		free(buffer);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		i;
	ssize_t		j;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (1)
	{
		if (j == 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				break ;
			buffer[bytes_read] = '\0';
		}
		while (buffer[j] && buffer[j] != '\n')
		{
			line[i] = buffer[j];
			i++;
			j++;
		}
		if (buffer[j] == '\n')
		{
			line[i] = buffer[j];
			i++;
			j++;
			break ;
		}
		if (j >= BUFFER_SIZE)
			j = 0;
	}
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

/*
#include <fcntl.h>

int main (void)
{
	int 	fd;
	char	*txt;
	int		i;
	
	fd = open("a.txt",  O_RDONLY);
	txt = malloc(1024 * sizeof(char));
	i = 0;
	while (i < 12)
	{
		txt = get_next_line(fd);
		write(1, txt, 50);
		i++;
	}
	close(fd);
	return (0);
}
*/