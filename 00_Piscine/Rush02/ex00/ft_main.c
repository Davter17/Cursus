/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:01:29 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/24 21:14:10 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
char	**ft_read_document(char *file_name);
void	ft_process_number(char **dict, char *number);

// Frees the allocated memory for the dictionary.
void	free_dict(char **dict)
{
	int	i;

	if (dict == NULL)
		return ;
	i = 0;
	while (dict[i] != NULL)
	{
		free(dict[i]);
		i++;
	}
	free(dict);
}

// Prints the corresponding value from the dictionary for a given key.
void	ft_print_number(char **dict, char *key)
{
	int		i;
	char	*entry_key;
	char	*value;

	i = 0;
	while (dict[i] != NULL)
	{
		entry_key = dict[i];
		value = ft_strchr(entry_key, ':');
		if (value == NULL)
		{
			i++;
			continue ;
		}
		*value = '\0';
		value++;
		if (ft_strcmp(entry_key, key) == 0)
		{
			write(1, value, ft_strlen(value));
			*--value = ':';
			return ;
		}
		*--value = ':';
		i++;
	}
}

// Checks if a given string contains only numeric characters.
int	ft_str_is_numeric(char *str)
{
	char	*an_str;
	int		incremental;

	incremental = 0;
	an_str = "0123456789";
	if (an_str[incremental] == '\0')
		return (1);
	while (*str != '\0')
	{
		while (an_str[incremental] != '\0')
		{
			if (*str == an_str[incremental])
			{
				incremental = 0;
				str++;
				break ;
			}
			else
				incremental++;
		}
		if (an_str[incremental] == '\0')
			return (0);
	}
	return (1);
}

// Main function that processes the number and outputs its value in words.
void	ft_rush02(char *file_name, char *number)
{
	char	**dict;

	dict = ft_read_document(file_name);
	if (dict == NULL)
		return ;
	if (ft_str_is_numeric(number) == 0)
	{
		write(1, "Error\n", 6);
		return ;
	}
	ft_process_number(dict, number);
	free_dict(dict);
}

// Main entry point that handles command-line arguments and calls the rush02.
int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rush02("numbers.dict", argv[1]);
	else if (argc == 3)
		ft_rush02(argv[1], argv[2]);
	else
		write(1, "Error\n", 6);
	return (0);
}
