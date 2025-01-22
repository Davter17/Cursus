/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:03:50 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 17:03:53 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Writes the character `c` to the file descriptor `fd`.

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <fcntl.h>

int main(void)
{
	int	fd;

	fd = open("a.txt", O_WRONLY);
	ft_putchar_fd('b', fd);
	close(fd);
	return (0);
}
*/