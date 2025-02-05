/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:40 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/05 14:47:06 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

typedef struct s_fd_buffer {
	int fd;
	char *buffer;
	struct s_fd_buffer *next;
} t_fd_buffer;

static t_fd_buffer *fd_buffers = NULL;  // Único atributo estático para manejar todos los buffers

// Buscar el buffer para un descriptor de archivo específico
t_fd_buffer *get_fd_buffer(int fd) {
	t_fd_buffer *temp = fd_buffers;
	while (temp) {
		if (temp->fd == fd)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

// Crear un nuevo buffer para un descriptor de archivo
t_fd_buffer	*create_fd_buffer(int fd)
{
	t_fd_buffer *new;
	
	new = malloc(sizeof(t_fd_buffer));
	if (!new)
		return NULL;
	new->fd = fd;
	new->buffer = ft_strdup("");
	new->next = fd_buffers;
	fd_buffers = new;
	return (new);
}

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

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + (buffer[i] == '\n'));
	return (line);
}

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

char	*get_next_line(int fd)
{
	t_fd_buffer	*fd_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_buf = get_fd_buffer(fd);
	if (!fd_buf)
		fd_buf = create_fd_buffer(fd);
	if (!fd_buf)
		return (NULL);
	fd_buf->buffer = read_and_store(fd, fd_buf->buffer);
	if (!fd_buf->buffer)
		return (NULL);
	line = extract_line(fd_buf->buffer);
	fd_buf->buffer = update_buffer(fd_buf->buffer);
	return (line);
}
