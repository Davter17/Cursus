/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:32:10 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/12 06:49:25 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nums(int *nums, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &"0123456789"[nums[i]], 1);
		i++;
	}
}

void	ft_increment_nums(int *nums, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		if (nums[i] < 9 - (n - 1 - i))
		{
			nums[i]++;
			while (++i < n)
				nums[i] = nums[i - 1] + 1;
			return ;
		}
		i--;
	}
}

void	ft_print_combn(int n)
{
	int	nums[10];
	int	i;

	i = 0;
	while (i < n)
	{
		nums[i] = i;
		i++;
	}
	while (nums[0] <= (10 - n))
	{
		ft_print_nums(nums, n);
		if (nums[0] < 10 - n)
			write(1, ", ", 2);
		ft_increment_nums(nums, n);
	}
}

/*
int	main(void)
{
	ft_print_combn(2);
	return (0);
}
*/
