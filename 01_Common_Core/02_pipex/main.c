/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:00:22 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/16 16:38:20 by mpico-bu         ###   ########.fr       */
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
		exit(1);
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
		exit(127);
	}
}

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

pid_t	create_child(const char *cmd, int input_fd, int output_fd, int close_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(close_fd);
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		execlp("sh", "sh", "-c", cmd, NULL);
		exit(127);
	}
	return (pid);
}

int	wait_for_processes(pid_t pid1, pid_t pid2)
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
		return (1);
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
	return (wait_for_processes(pid1, pid2));
}
