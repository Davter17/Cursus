/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:47:38 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/24 20:30:16 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
void	ft_print_number(char **dict, char *key);
void	ft_triplet(char **dict, char *triplet, char *magnitude, int is_last);

// Checks if a triplet contains any non-zero digits.
int	ft_is_nonzero_triplet(char *triplet)
{
	if (triplet[0] != '0' || triplet[1] != '0' || triplet[2] != '0')
		return (1);
	return (0);
}

// Checks if the number is zero, and if so, prints "0" and returns 1.
int	ft_is_zero_case(char **dict, char *number)
{
	if (ft_strlen(number) == 1 && number[0] == '0')
	{
		ft_print_number(dict, "0");
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

// Splits a number into triplets for processing.
void	ft_split_tri(char *number, int len, char tri[32][4], int *tri_index)
{
	int	start;
	int	i;

	while (len > 0)
	{
		if (len - 3 > 0)
			start = len - 3;
		else
			start = 0;
		i = 0;
		while (i < 3)
		{
			tri[*tri_index][i] = '0';
			i++;
		}
		tri[*tri_index][3] = '\0';
		i = 0;
		while (start + i < len)
		{
			tri[*tri_index][3 - (len - start) + i] = number[start + i];
			i++;
		}
		(*tri_index)++;
		len -= 3;
	}
}

// Prints the triplets along with their corresponding magnitudes.
void	ft_print_tri(char **dict, char tri[32][4], char **magnitudes, int count)
{
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		if (ft_is_nonzero_triplet(tri[i]))
		{
			ft_triplet(dict, tri[i], magnitudes[i], i == 0);
		}
		i--;
	}
}

// Processes a number by splitting it into triplets and printing them.
void	ft_process_number(char **dict, char *number)
{
	int		len;
	int		triplet_index;
	char	triplets[32][4];
	char	*magnitudes[14];

	magnitudes[0] = "";
	magnitudes[1] = "1000";
	magnitudes[2] = "1000000";
	magnitudes[3] = "1000000000";
	magnitudes[4] = "1000000000000";
	magnitudes[5] = "1000000000000000";
	magnitudes[6] = "1000000000000000000";
	magnitudes[7] = "1000000000000000000000";
	magnitudes[8] = "1000000000000000000000000";
	magnitudes[9] = "1000000000000000000000000000";
	magnitudes[10] = "1000000000000000000000000000000";
	magnitudes[11] = "1000000000000000000000000000000000";
	magnitudes[12] = "1000000000000000000000000000000000000";
	if (ft_is_zero_case(dict, number))
		return ;
	len = ft_strlen(number);
	triplet_index = 0;
	ft_split_tri(number, len, triplets, &triplet_index);
	ft_print_tri(dict, triplets, magnitudes, triplet_index);
}
