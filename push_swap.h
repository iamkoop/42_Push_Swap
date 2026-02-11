/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:31:22 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/11 01:36:52 by nilsdruon        ###   ########.fr       */
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
	int *arr;
	int count;
} t_arr;

int input_is_valid(char **input);
int **unsorted_and_sorted(t_arr *arr);
t_arr *convert_input_to_i_arr(char **input);
t_stack *create_initial_stack(t_arr *input_arr);
int *sorted_arr(int *arr, int size);
t_stack *ps_lstnew(int content, int index);
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);
void sort_3(t_stack **s);

#endif
