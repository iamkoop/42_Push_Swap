/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_stack_creation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:16:58 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/05 23:55:02 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static t_stack *free_and_ret_stack()
{
	return (NULL);
}

static int free_and_ret_i()
{
	return(0);
} */
static int find_index(int num, int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if(arr[i] == num)
			return (i);
		i++;
	}
	return(0);
}

static int fill_stack(int **arr_u_and_s, t_stack *new, t_stack *first, int size)
{
	t_stack	*prev;
	int i;
	
	i = 1;

	prev = new;
	while (i < size)
	{
		new = ft_lstnew(arr_u_and_s[0][i], find_index(arr_u_and_s[0][i], arr_u_and_s[1], size));
		if(!new)
			return(0);
		new->prev = prev;
		prev->next = new;
		prev = new;
		if(i == size - 1)
			break;
		else
			new = new->next;
		i++;
	}
	new->next = first;
	first->prev = new;
	return (1);
}

t_stack	*create_initial_stack(char	**input, int argc)
{
	int **arrays;
	int size;
	t_stack *stack;
	t_stack *new;

	size = 0;
	arrays = unsorted_and_sorted(input, argc, &size);
	if(!arrays)
		return(NULL);
	new = ft_lstnew(arrays[0][0], find_index(arrays[0][0], arrays[1], size));
	if(!new)
		return(NULL);
	stack = new;
	if(!stack)
		return (NULL);
	if(!fill_stack(arrays, new, new, size))
		return(NULL);
	return (stack);
}
