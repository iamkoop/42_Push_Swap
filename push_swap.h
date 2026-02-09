/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:31:22 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/09 22:41:31 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft_lib/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int input_is_valid(char **input);
int **unsorted_and_sorted(char **input, int *size);
t_stack *create_initial_stack(char **input);
// int *convert_input_to_arr(int argc, char **argv);
t_stack *ps_lstnew(int content, int index);
// void sa(t_stack **a);
// void sb(t_stack **b);

#endif
