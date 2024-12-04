/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:35:03 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/10 19:08:40 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char character);
void	ft_putstr(char *str);

void	ft_up_line(int x)
{
	int	counter;

	ft_putchar('o');
	if (x > 2)
	{
		counter = 2;
		while (counter < x)
		{
			ft_putchar('-');
			counter++;
		}
	}
	if (x > 1)
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	ft_middle_lines(int x, int y)
{
	int	counter_y;
	int	counter_x;

	counter_x = 1;
	counter_y = 2;
	while (counter_y < y)
	{
		if (counter_x == 1 || counter_x == x)
		{
			ft_putchar('|');
			counter_x++;
		}
		else if (counter_x < x)
		{
			ft_putchar(' ');
			counter_x++;
		}
		else
		{
			ft_putchar('\n');
			counter_y++;
			counter_x = 1;
		}
	}
}

void	ft_last_line(int x)
{
	int	counter;

	ft_putchar('o');
	if (x > 2)
	{
		counter = 2;
		while (counter < x)
		{
			ft_putchar('-');
			counter++;
		}
	}
	if (x > 1)
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	char	*phrase_error;

	phrase_error = "Error: Please enter only positive values.";
	if (x > 0 && y > 0)
	{
		ft_up_line(x);
		if (y > 1)
		{
			ft_middle_lines(x, y);
			ft_last_line(x);
		}
	}
	else
	{
		ft_putstr(phrase_error);
		ft_putchar('\n');
	}
}
