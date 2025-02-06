/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:55:11 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/06 02:55:11 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*read_and_join(int fd, char *saved)
{
	char	*buffer;
	int		rd;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	rd = 1;
	while (rd > 0 && ft_strchr(saved, '\n') == NULL)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		tmp = ft_strjoin(saved, buffer);
		saved = tmp;
	}
	free(buffer);
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*saved[1024];

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	saved[fd] = read_and_join(fd, saved[fd]);
	if (saved[fd] == NULL)
		return (NULL);
	line = ft_get_line(saved[fd]);
	tmp = ft_save(saved[fd]);
	saved[fd] = tmp;
	return (line);
}
