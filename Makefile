# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 14:28:47 by nildruon          #+#    #+#              #
#    Updated: 2026/02/10 00:09:08 by nilsdruon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra -g -Ilibft

CFILES = operations/reverse_rotate.c operations/rotate.c operations/swap.c \
input_check.c input_conversion.c input_sort.c initial_stack_creation.c\
main.c

OFILES = $(CFILES:.c=.o)


NAME = push_swap

HEADER = pushswap.h

LIBFT = libft_lib
LIBFT_A = $(LIBFT)/libft.a
CREATE = ar rcs

REMOVE = rm -f


%.o: %.c  $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OFILES) $(LIBFT_A) -o $(NAME)

fclean: clean
	$(REMOVE) $(NAME)
	@make -C $(LIBFT) fclean

clean:
	$(REMOVE) $(OFILES)
	@make -C $(LIBFT) clean

re: fclean all

.PHONY: all clean fclean re