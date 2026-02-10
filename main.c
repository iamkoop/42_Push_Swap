/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:45 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/10 01:17:38 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks *create_stacks()
{
	t_stacks *stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	return (stacks);
}

void print_stack(t_stack *stack)
{
	t_stack *s = stack;
	if (!stack)
		return;
	int cnt = 0;

	printf("Stack A\n");
	printf("-------------------------------------------------------------------"
		   "----------\n");
	printf("Node %d\n", cnt);
	printf("data       :%d\n", stack->data);
	printf("curr index :%d\n", stack->index);
	printf("prev index :%d\n", stack->prev->index);
	printf("next index :%d\n", stack->next->index);
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
		printf("curr index :%d\n", stack->index);
		printf("prev index :%d\n", stack->prev->index);
		printf("next index :%d\n", stack->next->index);
		printf("---------------------------------------------------------------"
			   "--------------\n");
		stack = stack->next;
		cnt++;
	}
}

static t_stack *create_initial_stack_from_args(char **input)
{
	t_arr *input_arr;

	input_arr = convert_input_to_i_arr(input);
	return (create_initial_stack(input_arr));
}

int main(int argc, char **argv)
{
	t_stacks *stacks;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (!input_is_valid(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stacks = create_stacks();
	if (!stacks)
		return (0);

	stacks->stack_a = create_initial_stack_from_args(argv);

	if (!stacks->stack_a)
		return (0);
	print_stack(stacks->stack_a);
	free(stacks);
	return (1);
}
