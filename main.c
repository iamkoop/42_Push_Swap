/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:45 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/25 23:17:28 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*create_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	return (stacks);
}

static t_stack	*create_initial_stack_from_args(char **input)
{
	t_arr	*input_arr;
	t_stack	*stack;

	input_arr = convert_input_to_i_arr(input);
	if (!input_arr)
		return (NULL);
	stack = create_initial_stack(input_arr);
	free(input_arr);
	if (!stack)
		return (NULL);
	return (stack);
}

static int	is_sorted(t_stack **stack)
{
	t_stack	*s;

	if (!stack | !*stack)
		return (1);
	s = *stack;
	while (s->next != *stack)
	{
		if (s->index > s->next->index)
		{
			return (0);
		}
		s = s->next;
	}
	ft_lstclear(stack);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
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
	if (is_sorted(&stacks->stack_a))
		return (free(stacks), 0);
	if (!stacks->stack_a)
		return (free(stacks), 0);
	sort(argc, &stacks->stack_a, &stacks->stack_b);
	ft_lstclear(&stacks->stack_a);
	free(stacks);
	return (1);
}
