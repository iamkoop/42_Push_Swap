# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 14:28:47 by nildruon          #+#    #+#              #
#    Updated: 2026/02/20 05:25:59 by nilsdruon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra -g -Ilibft_lib

CFILES = p_operations/reverse_rotate.c p_operations/rotate.c p_operations/swap.c \
p_parsing/input_check.c p_parsing/input_conversion.c p_parsing/input_sort.c p_parsing/initial_stack_creation.c \
p_sort/sort.c p_sort/turk_help.c p_sort/turk_algo.c p_sort/turk_cost_to_top.c p_sort/exec_operations.c p_sort/turk_sort_main.c \
main.c

OFILES = $(CFILES:.c=.o)


NAME = push_swap

HEADER = push_swap.h

LIBFT = libft_lib
LIBFT_A = $(LIBFT)/libft.a
CREATE = ar rcs

REMOVE = rm -f


%.o: %.c  $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT_A) -o $(NAME)

fclean: clean
	$(REMOVE) $(NAME)
	@make -C $(LIBFT) fclean

clean:
	$(REMOVE) $(OFILES)
	@make -C $(LIBFT) clean

re: fclean all

.PHONY: all clean fclean re