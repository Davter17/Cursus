/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:40 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 20:54:46 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Reads from file descriptor and stores data in buffer until '\n' or EOF.  
char	*read_and_store(int fd, char *buffer)
{
	char	*read_buf;
	int		bytes_read;

	read_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buf)
		return (free(buffer), NULL);
	bytes_read = read(fd, read_buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		read_buf[bytes_read] = '\0';
		buffer = ft_strjoin_and_replace(buffer, read_buf);
		if (!buffer)
			return (free(read_buf), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
	}
	free(read_buf);
	if (bytes_read == -1)
		return (free(buffer), NULL);
	return (buffer);
}

// Extracts a full line from the buffer up to the first '\n'.  
char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + (buffer[i] == '\n'));
	return (line);
}

// Updates the buffer by removing the extracted line.  
char	*update_buffer(char *buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = ft_strdup(buffer + i + 1);
	free(buffer);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

// Retrieves the next line from the file descriptor.  
char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	buffer[fd] = read_and_store(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	int fd2;
	char *line;
	int	i;
	
	fd =  open("a.txt", O_RDONLY);
	fd2 = open("b.txt", O_RDONLY);
	printf("%i\n\n%i\n\n", fd, fd2);
	line = get_next_line(fd);
	if (!line)
		line = get_next_line(fd2);
	if (!line)
		return (0);
	i = 2;
	while (line)
	{
		printf("%s", line);
		if (i == 1)
		{
			line = get_next_line(fd);
			if (!line)
				line = get_next_line(fd2);
			i = 2;
		}
		else if (i == 2)
		{
			line = get_next_line(fd2);
			if (!line)
				line = get_next_line(fd);
			i = 1;
		}
	}
	return (0);
}

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s