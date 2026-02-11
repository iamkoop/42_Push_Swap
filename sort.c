/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 00:05:35 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/11 01:42:05 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stddef.h>

static void sort_3_help(t_stack **s, int op1, int op2)
{

	if (op1 == 1 || op2 == 1)
	{
		write(2, "ra\n", 3);
		ra(s);
	}
	if (op1 == 2 || op2 == 2)
	{
		write(2, "rra\n", 4);
		rra(s);
	}
	if (op1 == 3 || op2 == 3)
	{
		write(2, "sa\n", 3);
		sa(s);
	}
	return;
}

void sort_3(t_stack **s)
{
	int first;
	int second;
	int third;

	first = (*s)->index;
	second = (*s)->next->index;
	third = (*s)->prev->index;
	if (first < second && second < third)
		sort_3_help(s, 0, 0);
	else if (first < second && second > third && third > first)
		sort_3_help(s, 2, 3);
	else if (first > second && second < third && third > first)
		sort_3_help(s, 3, 0);
	else if (first < second && second > third && third < first)
		sort_3_help(s, 2, 0);
	else if (first > second && second < third && third < first)
		sort_3_help(s, 1, 0);
	else if (first > second && second > third)
		sort_3_help(s, 1, 3);
}
