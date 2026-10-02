/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_triplet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:45:42 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/24 20:44:33 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
void	ft_print_number(char **dict, char *key);

// Processes the hundreds place of a triplet and prints its value.
void	ft_process_hundreds(char **dict, char *triplet, int *has_previous)
{
	if (triplet[0] != '0')
	{
		ft_print_number(dict, (char []){triplet[0], '\0'});
		write(1, " ", 1);
		ft_print_number(dict, "100");
		*has_previous = 1;
	}
}

// Processes the tens place of a triplet and prints its value.
void	ft_process_tens(char **dict, char *triplet, int *has_previous)
{
	if (triplet[1] == '1')
	{
		if (*has_previous)
			write(1, " ", 1);
		ft_print_number(dict, (char []){triplet[1], triplet[2], '\0'});
		*has_previous = 1;
	}
	else if (triplet[1] != '0')
	{
		if (*has_previous)
			write(1, " ", 1);
		ft_print_number(dict, (char []){triplet[1], '0', '\0'});
		*has_previous = 1;
	}
}

// Processes the units place of a triplet and prints its value.
void	ft_process_units(char **dict, char *triplet, int *has_previous)
{
	if (triplet[1] != '1' && triplet[2] != '0')
	{
		if (*has_previous)
			write(1, " ", 1);
		ft_print_number(dict, (char []){triplet[2], '\0'});
		*has_previous = 1;
	}
}

// Processes the magnitude (e.g., thousand, million) and prints it if present.
void	ft_process_magnitude(char **dict, char *magnitude, int *has_previous)
{
	if (magnitude != NULL && ft_strlen(magnitude) > 0)
	{
		if (*has_previous)
			write(1, " ", 1);
		ft_print_number(dict, magnitude);
		*has_previous = 1;
	}
}

// Processes a full triplet, including hundreds, tens, units, and magnitude.
void	ft_triplet(char **dict, char *triplet, char *magnitude, int is_last)
{
	int	has_previous;

	has_previous = 0;
	ft_process_hundreds(dict, triplet, &has_previous);
	ft_process_tens(dict, triplet, &has_previous);
	ft_process_units(dict, triplet, &has_previous);
	ft_process_magnitude(dict, magnitude, &has_previous);
	if (!is_last)
		write(1, " ", 1);
	else
		write(1, "\n", 1);
}
