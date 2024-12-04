# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 19:09:35 by mpico-bu          #+#    #+#              #
#    Updated: 2024/11/28 19:12:09 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = srcs
INCLUDES_DIR = includes

SRCS = $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_swap.c $(SRCS_DIR)/ft_putstr.c $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I $(INCLUDES_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creando la librería $(NAME)"
	@ar rcs $@ $^

%.o: %.c
	@echo "Compilando $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Eliminando archivos objetos"
	@rm -f $(OBJS)

fclean: clean
	@echo "Eliminando la librería $(NAME)"
	@rm -f $(NAME)

re: fclean all
