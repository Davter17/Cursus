# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 11:31:12 by mpico-bu          #+#    #+#              #
#    Updated: 2025/02/24 12:18:37 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLX = minilibx-linux/libmlx.a -L/usr/lib -lXext -lX11 -lm
LIBFT = libft/libft.a  # Si usas libft

SRCS = src/main.c src/map_parser.c src/render.c src/player.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) minilibx-linux/libmlx.a $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) $(LIBFT) -o $(NAME)

minilibx-linux/libmlx.a:
	make -C minilibx-linux

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C minilibx-linux clean
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C minilibx-linux clean
	make -C libft fclean

re: fclean all
