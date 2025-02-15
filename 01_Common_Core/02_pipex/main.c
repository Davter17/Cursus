/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:00:22 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/15 19:06:49 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void	execute_command(const char *cmd, int input_fd, int output_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		if (output_fd != STDOUT_FILENO)
		{
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}
		execlp("sh", "sh", "-c", cmd, NULL);
		perror("execlp");
		exit(127);
	}
}

int	main(int argc, char **argv)
{
	int	fd_in;
	int	fd_out;
	int	pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (perror("Error: Introduzca exactamente 4 parámetros"), 1);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		return (perror("Error al abrir fd_in"), 1);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		close(fd_in);
		return (perror("Error al abrir fd_out"), 1);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("Error en pipe");
		close(fd_in);
		close(fd_out);
		return (1);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		close(pipe_fd[0]);
		dup2(fd_in, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(fd_in);
		close(pipe_fd[1]);
		execlp("sh", "sh", "-c", argv[2], NULL);
		perror("execlp");
		exit(127);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(fd_out);
		execlp("sh", "sh", "-c", argv[3], NULL);
		perror("execlp");
		exit(127);
	}
	close(fd_in);
	close(fd_out);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
