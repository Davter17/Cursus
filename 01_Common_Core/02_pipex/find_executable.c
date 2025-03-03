/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:00:22 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/03 12:37:10 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Devuelve el valor de la variable de entorno PATH.
char	*get_path_env(void)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (ft_strnstr(environ[i], "PATH=", 5))
			return (&environ[i][5]);
		i++;
	}
	return (NULL);
}

// Concatena un directorio y comando en una ruta completa.
char	*join_path(const char *dir, const char *command)
{
	char	*full_path;
	size_t	len;

	len = ft_strlen(dir) + ft_strlen(command) + 2;
	full_path = malloc(len * sizeof(char));
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, dir, len);
	ft_strlcat(full_path, "/", len);
	ft_strlcat(full_path, command, len);
	return (full_path);
}

// Busca un ejecutable en los directorios de PATH.
char	*find_executable(char *command)
{
	char	*path;
	char	**dirs;
	char	*full_path;
	int		i;

	if (access(command, X_OK) == 0)
		return (ft_strdup(command));
	path = get_path_env();
	dirs = ft_split(path, ':');
	if (!path || !dirs)
		return (NULL);
	i = 0;
	while (dirs[i])
	{
		full_path = join_path(dirs[i++], command);
		if (full_path && access(full_path, X_OK) == 0)
		{
			free_array2(dirs);
			return (full_path);
		}
		free(full_path);
	}
	free_array2(dirs);
	return (NULL);
}
