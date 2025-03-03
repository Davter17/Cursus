/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:35:02 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/03 14:32:33 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include "libft/ft_printf.h"

extern char	**environ;

char	*get_path_env(void);
char	*join_path(const char *dir, const char *command);
char	*find_executable(char *command);

char	**parse_command(const char *cmd);
void	execute_child(const char *cmd, int input_fd, int output_fd);
pid_t	create_child(const char *cmd, int in_fd, int out_fd, int close_fd);
