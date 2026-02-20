/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 01:12:36 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/20 02:46:38 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int calc_max(t_stack **s)
{
	int max;
	t_stack *tmp;

	max = -1;
	tmp = *s;
	while (1)
	{
		max++;
		tmp = tmp->next;
		if (tmp == *s)
			break;
	}
	return (max);
}

static int calc_up_or_down(int location, int max, int *num_op)
{
	if (location <= max / 2)
	{
		*num_op = location;
		return (1);
	}
	else
		*num_op = (location - max) - 1;
	return (0);
}
static void move_help(t_stack **a, t_stack **b, int num_op_a, int num_op_b)
{
	while (num_op_a < 0)
	{
		num_op_a++;
		rra(a, 1);
	}
	while (num_op_b < 0)
	{
		num_op_b++;
		rrb(b, 1);
	}

	while (num_op_a > 0)
	{
		ra(a, 1);
		num_op_a--;
	}

	while (num_op_b > 0)
	{
		num_op_b--;
		rb(b, 1);
	}
}
static void move(t_stack **a, t_stack **b, int *a_data, int *b_data)
{
	if (a_data[1] && b_data[1])
	{
		while (a_data[2] > 0 && b_data[2] > 0)
		{
			rr(a, b);
			a_data[2]--;
			b_data[2]--;
		}
	}
	if (!a_data[1] && !b_data[1])
	{
		while (a_data[2] < 0 && b_data[2] < 0)
		{
			rrr(a, b);
			a_data[2]++;
			b_data[2]++;
		}
	}
	move_help(a, b, a_data[2], b_data[2]);
}

void exec_op(t_stack **a, t_stack **b, t_o_p *l_move_num)
{
	int up_a;
	int num_op_a;
	int up_b;
	int num_op_b;
	int a_data[3];
	int b_data[3];

	a_data[0] = calc_max(a);
	b_data[0] = calc_max(b);
	up_a = calc_up_or_down(l_move_num->loc_a, a_data[0], &num_op_a);
	up_b = calc_up_or_down(l_move_num->loc_b, b_data[0], &num_op_b);

	a_data[1] = up_a;
	a_data[2] = num_op_a;
	b_data[1] = up_b;
	b_data[2] = num_op_b;

	move(a, b, a_data, b_data);
}
