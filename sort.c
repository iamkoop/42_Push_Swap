/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 00:05:35 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/12 01:13:02 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_help(t_stack **s, int op1, int op2)
{
	if (op1 == 1 || op2 == 1)
		ra(s);
	if (op1 == 2 || op2 == 2)
		rra(s);
	if (op1 == 3 || op2 == 3)
		sa(s);
	return ;
}

void	sort_3(t_stack **s)
{
	int	first;
	int	second;
	int	third;

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

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*s;
	int		cost_to_top;

	s = *a;
	cost_to_top = 0;
	while (s->index != 0)
	{
		cost_to_top++;
		s = s->next;
	}
	if (cost_to_top == 0)
		pb(a, b);
	else if (cost_to_top <= 2)
	{
		while (cost_to_top-- > 0)
			ra(a);
	}
	else if (cost_to_top >= 3)
	{
		while (4 - cost_to_top-- > 0)
			rra(a);
	}
	sort_3(a);
	pa(a, b);
}

static void	rotate_to_top(t_stack **a, t_stack **b, int index)
{
	int		cost_to_top;
	t_stack	*s;

	s = *a;
	cost_to_top = 0;
	while (s->index != index)
	{
		cost_to_top++;
		s = s->next;
	}
	if (cost_to_top == 0)
		pb(a, b);
	else if (cost_to_top <= 2)
	{
		while (cost_to_top-- > 0)
			ra(a);
	}
	else if (cost_to_top >= 3)
	{
		while (4 - cost_to_top-- > 0)
			rra(a);
	}
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*s;

	s = *a;
	rotate_to_top(a, b, 0);
	pb(a, b);
	rotate_to_top(a, b, 1);
	pb(a, b);
	sort_3(a);
	while (*b)
		pa(a, b);
}
