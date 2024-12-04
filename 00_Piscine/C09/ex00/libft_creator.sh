# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 16:42:26 by mpico-bu          #+#    #+#              #
#    Updated: 2024/11/28 21:20:48 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
SRC_FILES="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"
cc -Wall -Werror -Wextra -c $SRC_FILES
ar rcs libft.a *.o
rm -f *.o
