/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:31:22 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/20 05:18:26 by nilsdruon        ###   ########.fr       */
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

// optimal push
typedef struct s_o_p
{
	int loc_a;
	int loc_b;
	int total_cost;
} t_o_p;

int input_is_valid(char **input);
int **unsorted_and_sorted(t_arr *arr);
t_arr *convert_input_to_i_arr(char **input);
t_stack *create_initial_stack(t_arr *input_arr);
int *sorted_arr(int *arr, int size);
void sort(int argc, t_stack **a, t_stack **b);
void sort_turk(t_stack **a, t_stack **b);
void sa(t_stack **a, int print);
void sb(t_stack **b, int print);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a, int write);
void rb(t_stack **b, int write);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a, int print);
void rrb(t_stack **b, int print);
void rrr(t_stack **a, t_stack **b);
void sort_3(t_stack **s);
void sort_4(t_stack **a, t_stack **b);
void sort_5(t_stack **a, t_stack **b);
void find_smallest_op_and_exec(t_stack **a, t_stack **b);
int ft_cttp(int max_a, int max_b, int current_a, int current_b);
void exec_op(t_stack **a, t_stack **b, t_o_p *l_move_num);

#endif
