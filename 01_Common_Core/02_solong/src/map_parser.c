/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:43:56 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/24 15:49:50 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

char **read_map(char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("No se pudo abrir el archivo.\n");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map = realloc(map, sizeof(char *) * (i + 2));
		map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	parse_map(t_game *game, char *file)
{
	game->map = read_map(file);
	if (!game->map)
		error_exit("Mapa inválido.\n");
	return (0);
}

/*
void	read_map(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		write(1, line, ft_strlen(line));
		line = get_next_line(fd);
	}
}

int check_map(char *fd_name)
{
	int	fd;
	int	i;

	i = 0;
	while(fd_name[i + 4])
		i++;
	if (fd_name[i] != '.' || fd_name[i + 1] != 'b' || fd_name[i + 2] != 'e' || fd_name[i + 3] != 'r')
		return (ft_printf("Error: El archivo debe de tener extensión .ber\n"), 0);
	fd = open(fd_name, O_RDONLY);
	if (fd == -1)
		{
			ft_printf("No se ha encontrado el archivo\n");
			close(fd);
			return (0);
		}
	read_map(fd);
	close(fd);
	return (1);
}
*/
