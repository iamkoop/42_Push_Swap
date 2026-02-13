/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/13 22:02:46 by nildruon         ###   ########.fr       */
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
	stack->curr_index = i;
	stack = stack->next;
	i++;
	while(stack != *a)
	{
		stack->curr_index = i++;
		stack = stack->next;
	}
	if(!b || !*b)
		return ;
	stack = *b;
	i = 0;
	stack->curr_index = i++;
	stack = stack->next;
	while(stack != *b)
	{
		stack->curr_index = i++;
		stack = stack->next;
	}
}

static void initial_push_to_b(t_stack **a, t_stack **b)
{
	t_stack *stack;
	int i;
	
	stack = *a;
	i = stack->prev->curr_index;
	while(i > 2)
	{
		pb(a,b);
		i--;
	}
	sort_3(a);
}

/*static int cost_to_top(t_stack **a,t_stack **b, int index_a, int index_b)
{
	return(0);
}*/

//must be between current num and next (most cost efficient out of those)
/*void find_smallest_op(t_stack **a,t_stack **b)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int cost_to_top;

	stack_a = *a;
	stack_b = *b
	
	while(stack_a->next)
	{
		while(stack_b->next)
		{
			if(stack_b->cur_index)
			stack_a = stack->next;
		}
		stack_a = stack->next;
	}
}*/

void sort_turk(t_stack **a,t_stack **b)
{
	index_a_b(a, b);
	initial_push_to_b(a,b);
	index_a_b(a, b);
	
}
