/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:09:25 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/03/03 12:16:12 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Libera un array de strings.
void	free_array2(char **array)
{
	int		i;

	if (!array)
		return ;
	i = 0;
	while (array[i++])
		free(array[i]);
	free(array);
}
