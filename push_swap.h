/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:31:22 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/10 00:24:08 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft_lib/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_arr
{
	int *data;
	int count;
} t_arr;

int input_is_valid(char **input);
int **unsorted_and_sorted(char **input, int *size);
t_stack *create_initial_stack_from_args(char **input);
int *convert_input_to_i_arr(char **input, int *size);
int *sorted_arr(int *arr, int size);
// int *convert_input_to_arr(int argc, char **argv);
t_stack *ps_lstnew(int content, int index);
// void sa(t_stack **a);
// void sb(t_stack **b);

#endif
