# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 16:00:14 by mpico-bu          #+#    #+#              #
#    Updated: 2024/11/28 15:04:39 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g
SRC = main.c matrix_size.c to_matrix.c solve_square.c free_resources.c processing.c
OBJ = $(SRC:.c=.o)
NAME = bsq

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) example_file4