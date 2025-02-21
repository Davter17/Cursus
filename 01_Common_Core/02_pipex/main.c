/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:00:22 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/21 15:18:19 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 100
extern char **environ;

// Implementación de ft_strdup
char *ft_strdup(const char *s)
{
    int len = 0;
    while (s[len])
        len++;
    char *dup = malloc(len + 1);
    if (!dup)
        return NULL;
    for (int i = 0; i <= len; i++)
        dup[i] = s[i];
    return dup;
}

// Obtener el valor de PATH desde environ
char *get_path_env()
{
    for (int i = 0; environ[i]; i++)
    {
        if (environ[i][0] == 'P' && environ[i][1] == 'A' &&
            environ[i][2] == 'T' && environ[i][3] == 'H' &&
            environ[i][4] == '=')
        {
            return &environ[i][5]; // Retorna la parte después de "PATH="
        }
    }
    return NULL;
}

// Función para concatenar directorio y comando
char *join_path(const char *dir, const char *command)
{
    int len_dir = 0, len_cmd = 0;
    while (dir[len_dir])
        len_dir++;
    while (command[len_cmd])
        len_cmd++;

    char *full_path = malloc(len_dir + len_cmd + 2);
    if (!full_path)
        return NULL;

    int i = 0;
    for (; i < len_dir; i++)
        full_path[i] = dir[i];
    full_path[i++] = '/';
    for (int j = 0; j < len_cmd; j++, i++)
        full_path[i] = command[j];
    full_path[i] = '\0';

    return full_path;
}

char *find_executable(char *command)
{
    if (access(command, X_OK) == 0)
        return ft_strdup(command);

    char *path = get_path_env();
    if (!path)
        return NULL;

    char *path_copy = ft_strdup(path);
    if (!path_copy)
        return NULL;

    char *dir = path_copy;
    while (*dir)
    {
        char *next = dir;
        while (*next && *next != ':')
            next++;
        if (*next)
            *next++ = '\0';

        char *full_path = join_path(dir, command);
        if (!full_path)
        {
            free(path_copy);
            return NULL;
        }

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }
        free(full_path);
        dir = next;
    }
    free(path_copy);
    return NULL;
}

char **parse_command(const char *cmd)
{
    char **args = malloc(sizeof(char *) * (MAX_ARGS + 1));
    if (!args)
    {
        perror("malloc");
        exit(1);
    }
    int i = 0;
    char *cmd_copy = ft_strdup(cmd);
    if (!cmd_copy)
    {
        perror("ft_strdup");
        exit(1);
    }
    char *token = cmd_copy;
    while (*token)
    {
        while (*token == ' ')
            token++;
        if (!*token)
            break;
        args[i++] = token;
        while (*token && *token != ' ')
            token++;
        if (*token)
        {
            *token = '\0';
            token++;
        }
    }
    args[i] = NULL;
    return args;
}

void execute_command(const char *cmd, int input_fd, int output_fd)
{
    pid_t pid = fork();
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
        char **args = parse_command(cmd);
        if (!args || !args[0])
        {
            perror("parse_command");
            exit(1);
        }
        char *executable = find_executable(args[0]);
        if (!executable)
        {
            write(STDERR_FILENO, "command not found\n", 18);
            exit(127);
        }
        execve(executable, args, environ);
        perror("execve");
        exit(127);
    }
    else
        waitpid(pid, NULL, 0);
}

int open_files(char *input, char *output, int *fd_in, int *fd_out)
{
    *fd_in = open(input, O_RDONLY);
    if (*fd_in == -1)
        *fd_in = open("/dev/null", O_RDONLY);
    *fd_out = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (*fd_out == -1)
    {
        close(*fd_in);
        return 0;
    }
    return 1;
}

pid_t create_child(const char *cmd, int input_fd, int output_fd, int close_fd)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        close(close_fd);
        dup2(input_fd, STDIN_FILENO);
        dup2(output_fd, STDOUT_FILENO);
        char **args = parse_command(cmd);
        if (!args || !args[0])
        {
            perror("parse_command");
            exit(1);
        }
        char *executable = find_executable(args[0]);
        if (!executable)
        {
            write(STDERR_FILENO, "command not found\n", 18);
            exit(127);
        }
        execve(executable, args, environ);
        perror("execve");
        exit(127);
    }
    return pid;
}

int wait_for_processes(pid_t pid1, pid_t pid2)
{
    int status;
    waitpid(pid1, NULL, 0);
    waitpid(pid2, &status, 0);
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return 1;
}

int main(int argc, char **argv)
{
    int fd_in, fd_out, pipe_fd[2];
    pid_t pid1, pid2;

    if (argc != 5)
        return 1;
    if (!open_files(argv[1], argv[4], &fd_in, &fd_out))
        return 1;
    if (pipe(pipe_fd) == -1)
        exit(1);
    pid1 = create_child(argv[2], fd_in, pipe_fd[1], pipe_fd[0]);
    pid2 = create_child(argv[3], pipe_fd[0], fd_out, pipe_fd[1]);
    close(fd_in);
    close(fd_out);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    return wait_for_processes(pid1, pid2);
}
