/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:00:22 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/23 19:58:23 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "libft/libft.h"

#define MAX_ARGS 100

extern char	**environ;

char	*get_path_env(void)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], "PATH=", 5))
			return (&environ[i][5]);
		i++;
	}
	return (NULL);
}

char	*join_path(const char *dir, const char *command)
{
	char	*full_path;
	size_t	len;

	len = ft_strlen(dir) + ft_strlen(command) + 2;
	full_path = malloc(len);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, dir, len);
	ft_strlcat(full_path, "/", len);
	ft_strlcat(full_path, command, len);
	return (full_path);
}

char	*find_executable(char *command)
{
	char	*path;
	char	**dirs;
	char	*full_path;
	int		i;

	if (access(command, X_OK) == 0)
		return (ft_strdup(command));
	path = get_path_env();
	if (!path)
		return (NULL);
	dirs = ft_split(path, ':');
	if (!dirs)
		return (NULL);
	i = 0;
	while (dirs[i])
	{
		full_path = join_path(dirs[i], command);
		if (!full_path)
			break ;
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	**parse_command(const char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("malloc");
		exit(1);
	}
	return (args);
}

void	execute_child(const char *cmd, int input_fd, int output_fd)
{
	char	**args;
	char	*executable;

	if (input_fd != STDIN_FILENO)
		dup2(input_fd, STDIN_FILENO);
	if (output_fd != STDOUT_FILENO)
		dup2(output_fd, STDOUT_FILENO);
	args = parse_command(cmd);
	if (!args || !args[0])
		exit(1);
	executable = find_executable(args[0]);
	if (!executable)
	{
		write(STDERR_FILENO, "command not found\n", 18);
		exit(127);
	}
	execve(executable, args, environ);
	perror("execve");
	exit(127);
}

void	execute_command(const char *cmd, int input_fd, int output_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		execute_child(cmd, input_fd, output_fd);
	else
		waitpid(pid, NULL, 0);
}

int	open_files(char *input, char *output, int *fd_in, int *fd_out)
{
	*fd_in = open(input, O_RDONLY);
	if (*fd_in == -1)
		*fd_in = open("/dev/null", O_RDONLY);
	*fd_out = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (*fd_out != -1);
}

pid_t	create_child(const char *cmd, int input_fd, int output_fd, int close_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(close_fd);
		execute_child(cmd, input_fd, output_fd);
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

	if (argc != 5 || !open_files(argv[1], argv[4], &fd_in, &fd_out))
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
