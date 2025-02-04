/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:40 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/04 23:26:49 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd, char *buffer, ssize_t *bytes_read)
{
	char	*tmp;
	char	*read_buf;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	*bytes_read = 1;
	while (*bytes_read > 0 && (!buffer || !ft_strchr(buffer, '\n')))
	{
		*bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (*bytes_read < 0)
		{
			free(read_buf);
			free(buffer);
			return (NULL);
		}
		read_buf[*bytes_read] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		if (!buffer)
		{
			free(read_buf);
			return (NULL);
		}
		tmp = ft_strjoin(buffer, read_buf);
		free(buffer);
		if (!tmp)
		{
			free(read_buf);
			return (NULL);
		}
		buffer = tmp;
	}
	free(read_buf);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	int		len;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = ft_substr(buffer, 0, len + (buffer[len] == '\n'));
	return (line);
}

char	*update_buffer(char *buffer)
{
	int		start;
	char	*new_buffer;

	if (!buffer)
		return (NULL);
	start = 0;
	while (buffer[start] && buffer[start] != '\n')
		start++;
	if (!buffer[start])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(buffer + start + 1);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_and_store(fd, buffer[fd], &bytes_read);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
