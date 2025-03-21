# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:15:41 by mpico-bu          #+#    #+#              #
#    Updated: 2025/02/12 11:23:21 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = 	ft_alloc.c ft_char_is.c ft_int_str.c ft_list_advance.c ft_list_basics.c \
		ft_mem_handle.c ft_put_in_fd.c ft_search_in_str.c ft_str_advance.c \
		ft_str_basics.c ft_str_chr_modify.c \
		ft_printf.c ft_printf_utils.c ft_printf_utils2.c \
		get_next_line.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $<
