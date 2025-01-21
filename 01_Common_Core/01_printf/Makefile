# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:51:55 by mpico-bu          #+#    #+#              #
#    Updated: 2025/01/20 22:44:03 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = cc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Ilibft -I.

.PHONY: all clean fclean re libft_clean libft_fclean

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME) # Copia libft.a en libftprintf.a
	ar rcs $(NAME) $(OBJS) # Añade los objetos de ft_printf al archivo

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