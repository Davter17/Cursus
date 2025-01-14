/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:47 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 12:22:49 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the character is printable, meaning it can be displayed on screen.

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
