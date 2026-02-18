/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/18 15:48:37 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stack_i(t_stack *stack, char c)
{
	t_stack *s = stack;
	if (!stack)
		return;
	int cnt = 0;

	if (c == 'a')
		printf("Stack A\n");
	if (c == 'b')
		printf("Stack B\n");
	printf("-------------------------------------------------------------------"
		   "----------\n");
	printf("Node %d\n", cnt);
	printf("data       :%d\n", stack->data);
	printf("curr index :%d\n", stack->curr_i);
	printf("sorted index :%d\n", stack->index);
	printf("prev index :%d\n", stack->prev->curr_i);
	printf("next index :%d\n", stack->next->curr_i);
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
		printf("sorted index :%d\n", stack->index);
		printf("curr index :%d\n", stack->curr_i);
		printf("prev index :%d\n", stack->prev->curr_i);
		printf("next index :%d\n", stack->next->curr_i);
		printf("---------------------------------------------------------------"
			   "--------------\n");
		stack = stack->next;
		cnt++;
	}
}

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

static void initial_push_to_b(t_stack **a, t_stack **b, int max)
{
	int len;
	int middle;

	middle = max / 2;
	len = (*a)->prev->curr_i;

	while ((*a)->index > middle)
		ra(a);
	while (len > 2)
	{
		if ((*a)->index <= middle)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
		len--;
	}
	sort_3(a);
}

void sort_turk(t_stack **a, t_stack **b)
{
	int max;
	t_stack *s;

	index_a_b(a, b);
	s = *a;
	max = 0;
	while (1)
	{
		if (s->index > max)
			max = s->index;
		s = s->next;
		if (s == *a)
			break;
	}
	initial_push_to_b(a, b, max);
	index_a_b(a, b);
	print_stack_i(*a, 'a');
	print_stack_i(*b, 'b');
	while (*b)
	{
		find_smallest_op_and_exec(a, b);
		index_a_b(a, b);
	}
}
