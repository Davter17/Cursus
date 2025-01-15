/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:40 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 01:48:37 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*c;
	int		i;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	c = malloc(sizeof(char));
	if (!c)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(c);
		return (NULL);
	}
	i = 0;
	while (read(fd, c, 1))
	{
		if (c[0] == '\n' || i >= BUFFER_SIZE)
			break ;
		buffer[i++] = c[0];
	}
	buffer[i] = '\0';
	return (buffer);
}

#include <fcntl.h>

int main (void)
{
	int 	fd;
	char	*txt;
	int		i;
	
	fd = open("a.txt",  O_RDONLY);
	txt = malloc(1024 * sizeof(char));
	i = 0;
	while (i < 5)
	{
		txt = get_next_line(fd);
		write(1, txt, 12);
		write(1, "\n", 1);
		i++;
	}
	close(fd);
	return (0);
}
