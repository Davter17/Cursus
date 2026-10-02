/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:47:46 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/22 12:54:18 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	calculate_total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;
	int	j;
	int	sep_len;

	total_len = 0;
	sep_len = 0;
	while (sep[sep_len] != '\0')
		sep_len++;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			total_len++;
			j++;
		}
		if (i < size - 1)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

void	copy_strings(int size, char **strs, char *sep, char *str_joined)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
		{
			str_joined[k] = strs[i][j];
			k++;
		}
		if (i < size - 1)
		{
			j = -1;
			while (sep[++j] != '\0')
			{
				str_joined[k] = sep[j];
				k++;
			}
		}
	}
	str_joined[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_joined;
	int		total_len;

	if (size == 0)
		return (malloc(1));
	total_len = calculate_total_length(size, strs, sep);
	str_joined = malloc((total_len + 1) * sizeof(char));
	if (str_joined == NULL)
		return (NULL);
	copy_strings(size, strs, sep, str_joined);
	return (str_joined);
}

/*
int main(int argc, char **argv)
{
	char	*str;

	if (argc > 1)
	{
		str = ft_strjoin(argc - 1, argv + 1, " | ");
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}		
	return (0);
}
*/
