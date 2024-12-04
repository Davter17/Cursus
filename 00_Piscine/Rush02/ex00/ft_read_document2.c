/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_document2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:06:56 by mpico-bu          #+#    #+#             */
/*   Updated: 2024/11/24 20:24:58 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str);

// Extracts a key from the buffer, ending at ':' and replaces it with '\0'.
char	*extract_key(char *buffer, int *i)
{
	char	*key_start;

	while (buffer[*i] == '\n' || buffer[*i] == ' ')
		(*i)++;
	key_start = &buffer[*i];
	while (buffer[*i] != ':' && buffer[*i] != '\0')
		(*i)++;
	if (buffer[*i] == '\0')
		return (NULL);
	buffer[(*i)++] = '\0';
	return (key_start);
}

// Extracts a value from the buffer, ending at '\n' or '\0'.
char	*extract_value(char *buffer, int *i)
{
	char	*value_start;

	while (buffer[*i] == '\n' || buffer[*i] == ' ')
		(*i)++;
	value_start = &buffer[*i];
	while (buffer[*i] != '\n' && buffer[*i] != '\0')
		(*i)++;
	if (buffer[*i] == '\n')
		buffer[(*i)++] = '\0';
	return (value_start);
}

// Allocates memory for a key-value pair string with the format "key:value".
char	*allocate_key_value_pair(char *key, char *value)
{
	char	*pair;
	int		length;

	length = ft_strlen(key) + ft_strlen(value) + 2;
	pair = malloc(length);
	if (pair == NULL)
		write(1, "Error\n", 6);
	return (pair);
}

// Copies key and value into a formatted "key:value" string and adds it to dict.
void	copy_to_dict(char *key, char *value, char **dict, int *j)
{
	char	*pair;
	int		k;

	pair = allocate_key_value_pair(key, value);
	if (pair == NULL)
		return ;
	k = 0;
	while (*key)
		pair[k++] = *key++;
	pair[k++] = ':';
	while (*value)
		pair[k++] = *value++;
	pair[k] = '\0';
	dict[*j] = pair;
	(*j)++;
}

// Parses and stores a key-value pair from buffer into dict.
void	parse_key_value(char *buffer, char **dict, int *i, int *j)
{
	char	*key_start;
	char	*value_start;

	key_start = extract_key(buffer, i);
	if (key_start == NULL)
		return ;
	value_start = extract_value(buffer, i);
	if (value_start == NULL)
		return ;
	copy_to_dict(key_start, value_start, dict, j);
}
