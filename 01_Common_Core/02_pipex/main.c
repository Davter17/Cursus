/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:00:22 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/03 14:32:16 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Abre archivos de entrada y salida, configurando descriptores.
int	open_files(char *input, char *output, int *fd_in, int *fd_out)
{
	*fd_in = open(input, O_RDONLY);
	if (*fd_in == -1)
		*fd_in = open("/dev/null", O_RDONLY);
	*fd_out = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_out == -1)
	{
		close(*fd_in);
		return (0);
	}
	return (1);
}

// Espera y devuelve el código de salida de dos procesos.
int	wait_end(pid_t pid1, pid_t pid2)
{
	int	status;

	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_printf("Error use: <input_file> <cmd1> <cmd2> <output_file>\n");
		return (1);
	}
	if (!open_files(argv[1], argv[4], &fd_in, &fd_out))
		return (1);
	if (pipe(pipe_fd) == -1)
		exit(1);
	pid1 = create_child(argv[2], fd_in, pipe_fd[1], pipe_fd[0]);
	pid2 = create_child(argv[3], pipe_fd[0], fd_out, pipe_fd[1]);
	close(fd_in);
	close(fd_out);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (wait_end(pid1, pid2));
}
