/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:30:07 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/15 21:30:07 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

void	ft_putnbr_fd(int n, int fd)
{
	char	*n_char;

	n_char = ft_itoa(n);
	if (n_char)
		write(fd, n_char, ft_strlen(n_char));
}
