/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:16:30 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/19 15:31:01 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i_str;
	int	i_to_find;

	i_str = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i_str] != '\0')
	{
		i_to_find = 0;
		while (str[i_str + i_to_find] == to_find[i_to_find])
		{
			i_to_find++;
			if (to_find[i_to_find] == '\0')
				return (&str[i_str]);
		}
		i_str++;
	}
	return (0);
}

/*
int	main(void)
{
	char	*str;
	char	*sub_str;
	char	*result;

	str = "Hello world.";
	sub_str = "ld.";
	result = ft_strstr(str, sub_str);
	if (result)
		write(1, result, 1);
	else
		write(1, "0", 1);
	return (0);
}
*/
