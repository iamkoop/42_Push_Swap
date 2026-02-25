/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/25 16:57:14 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	index_a_b(t_stack **a, t_stack **b)
{
	t_stack	*stack;
	int		i;

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
		return ;
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

static void	initial_push_to_b(t_stack **a, t_stack **b, int max)
{
	int	len;
	int	middle;

	middle = max / 2;
	len = (*a)->prev->curr_i;
	while ((*a)->index > middle)
		ra(a, 1);
	while (len > 2)
	{
		if ((*a)->index <= middle)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b, 1);
		}
		len--;
	}
	sort_3(a);
}

static void	set_into_final_position(t_stack **a, int cnt, int index, int max)
{
	t_stack	*tmp;

	tmp = *a;
	while (1)
	{
		cnt++;
		tmp = tmp->next;
		if (tmp == *a)
			break ;
	}
	if (cnt > max / 2)
	{
		while (index > 0)
		{
			rra(a, 1);
			index--;
		}
		return ;
	}
	while (cnt >= 0)
	{
		ra(a, 1);
		cnt--;
	}
}

void	sort_turk(t_stack **a, t_stack **b)
{
	int		max;
	t_stack	*s;

	index_a_b(a, b);
	s = *a;
	max = 0;
	while (1)
	{
		if (s->index > max)
			max = s->index;
		s = s->next;
		if (s == *a)
			break ;
	}
	initial_push_to_b(a, b, max);
	index_a_b(a, b);
	while (*b)
	{
		find_smallest_op_and_exec(a, b);
		index_a_b(a, b);
	}
	set_into_final_position(a, -1, (*a)->index, max);
}
