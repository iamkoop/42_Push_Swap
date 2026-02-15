/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/15 16:19:07 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void print_stack_i(t_stack *stack, char c)
{
	t_stack *s = stack;
	if (!stack)
		return;
	int cnt = 0;

	if(c == 'a')
		printf("Stack A\n");
	if(c == 'b')
		printf("Stack B\n");
	printf("-------------------------------------------------------------------"
		   "----------\n");
	printf("Node %d\n", cnt);
	printf("data       :%d\n", stack->data);
	printf("curr index :%d\n", stack->curr_index);
	printf("prev index :%d\n", stack->prev->curr_index);
	printf("next index :%d\n", stack->next->curr_index);
	printf("-------------------------------------------------------------------"
		   "----------\n");
	stack = stack->next;
	cnt++;
	while (stack != s)
	{
		printf("---------------------------------------------------------------"
			   "--------------\n");
		printf("Node %d\n", cnt);
		printf("data       :%d\n", stack->data);
		printf("curr index :%d\n", stack->curr_index);
		printf("prev index :%d\n", stack->prev->curr_index);
		printf("next index :%d\n", stack->next->curr_index);
		printf("---------------------------------------------------------------"
			   "--------------\n");
		stack = stack->next;
		cnt++;
	}
}*/

static void index_a_b(t_stack **a, t_stack **b)
{
	t_stack *stack;
	int i;

	i = 0;
	stack = *a;
	stack->curr_i = i;
	stack = stack->next;
	i++;
	while (stack != *a)
	{
		stack->curr_i = i++;
		stack = stack->next;
	}
	if (!b || !*b)
		return;
	stack = *b;
	i = 0;
	stack->curr_i = i++;
	stack = stack->next;
	while (stack != *b)
	{
		stack->curr_i = i++;
		stack = stack->next;
	}
}

static void initial_push_to_b(t_stack **a, t_stack **b)
{
	t_stack *stack;
	int i;

	stack = *a;
	i = stack->prev->curr_i;
	while (i > 2)
	{
		pb(a, b);
		i--;
	}
	sort_3(a);
}



void sort_turk(t_stack **a, t_stack **b)
{
	index_a_b(a, b);
	initial_push_to_b(a, b);
	index_a_b(a, b);
	while (*b)
	{
		find_smallest_op_and_exec(a, b);
		index_a_b(a, b);
	}
}
