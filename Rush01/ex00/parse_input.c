/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/19 20:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_number(char *str, int *i, int *num)
{
	int	count;

	count = 0;
	*num = 0;
	while (str[*i] == ' ')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*num = *num * 10 + (str[*i] - '0');
		(*i)++;
		count++;
	}
	while (str[*i] == ' ')
		(*i)++;
	return (count > 0);
}

int	parse_input(char *str, int *clues)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (j < 16)
	{
		if (!parse_number(str, &i, &num))
			return (0);
		if (num < 1 || num > 4)
			return (0);
		clues[j] = num;
		j++;
	}
	return (1);
}
