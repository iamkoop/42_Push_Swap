/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_stack_creation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:16:58 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/20 04:40:04 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_index(int num, int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (0);
}

static int fill_stack(int **arrs, t_stack *new, t_stack *first, int size)
{
	t_stack *prev;
	int i;

	i = 1;

	prev = new;
	while (i < size)
	{
		new = ft_lstnew(arrs[0][i], find_index(arrs[0][i], arrs[1], size));
		if (!new)
			return (ft_lstclear(&first), 0);
		new->prev = prev;
		prev->next = new;
		prev = new;
		if (i == size - 1)
			break;
		else
			new = new->next;
		i++;
	}
	new->next = first;
	first->prev = new;
	return (1);
}

t_stack *create_initial_stack(t_arr *input_arr)
{
	int **arrs;
	int size;
	t_stack *stack;
	t_stack *new;

	size = input_arr->count;

	arrs = unsorted_and_sorted(input_arr);
	if (!arrs)
		return (NULL);
	new = ft_lstnew(arrs[0][0], find_index(arrs[0][0], arrs[1], size));
	if (!new)
		return (free(arrs[0]), free(arrs[1]), free(arrs), NULL);
	stack = new;
	if (!stack)
		return (NULL);
	if (!fill_stack(arrs, new, new, input_arr->count))
		return (free(arrs[0]), free(arrs[1]), free(arrs), free(new), NULL);
	free(arrs[0]);
	free(arrs[1]);
	free(arrs);
	return (stack);
}
