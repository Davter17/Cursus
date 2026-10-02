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

void ft_print_combn(int n) {
	int i;
	int nums[n];

	i = 0;
    while (i < n) {
        nums[i] = i;
        i++;
    }
    while (nums[0] <= (10 - n)) {
        i = 0;
        while (i < n) {
            write(1, &"0123456789"[nums[i]], 1);
            i++;
        }
        if (nums[0] < 10 - n) {
            write(1, ", ", 2);
        }
        i = n - 1;
        while (i >= 0) {
            if (nums[i] < 9 - (n - 1 - i)) {
                nums[i]++;
                break;
            }
            i--;
        }
        if (i >= 0) {
            while (++i < n) {
                nums[i] = nums[i - 1] + 1;
            }
        }
    }
}

int	main(void)
{
	ft_print_combn(2);
}