/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:03:17 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 17:03:19 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Writes the integer `n` to the file descriptor `fd`.

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

/*
#include <fcntl.h>

int main(void)
{
	int	fd;

	fd = open("a.txt", O_WRONLY);
	ft_putnbr_fd(147, fd);
	close(fd);
	return (0);
}
*/