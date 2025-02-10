# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 00:43:56 by mpico-bu          #+#    #+#              #
#    Updated: 2025/02/10 01:09:51 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c swaps.c pushes.c rotates.c  reverse_rotates.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = cc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Ilibft

.PHONY: all clean fclean re libft_clean libft_fclean

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean: libft_clean
	rm -f $(OBJS)

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@