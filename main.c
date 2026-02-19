/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:45 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/19 02:00:21 by nildruon         ###   ########.fr       */
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

void sort(int argc, t_stack **a, t_stack **b)
{
	if (argc == 2)
		return;
	else if (argc == 3)
		sa(a);
	else if (argc == 4)
		sort_3(a);
	else if (argc == 5)
		sort_4(a, b);
	else if (argc == 6)
		sort_5(a, b);
	else if (argc > 6)
		sort_turk(a, b);
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
	stacks->stack_b = NULL;
	if (!stacks->stack_a)
		return (0);
	sort(argc, &stacks->stack_a, &stacks->stack_b);
	free(stacks);
	return (1);
}
