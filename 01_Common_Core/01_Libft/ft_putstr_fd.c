/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:19:46 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/12/15 21:19:46 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
