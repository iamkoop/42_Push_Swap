/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 00:05:35 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/03/19 20:30:08 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_3_help(t_stack **s, int op1, int op2)
{
	if (op1 == 1 || op2 == 1)
		ra(s, 1);
	if (op1 == 2 || op2 == 2)
		rra(s, 1);
	if (op1 == 3 || op2 == 3)
		sa(s, 1);
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

static int	find_smallest_num_i(t_stack **a)
{
	t_stack	*tmp;
	int		i;
	int		num;
	int		index_with_smlst_n;

	i = 0;
	index_with_smlst_n = 0;
	tmp = *a;
	num = tmp->data;
	while (1)
	{
		if (tmp->data < num)
		{
			num = tmp->data;
			index_with_smlst_n = i;
		}
		i++;
		tmp = tmp->next;
		if (tmp == *a)
			break ;
	}
	return (index_with_smlst_n);
}

static void	sort_5_help(t_stack	**a, t_stack	**b, int i, int smallest_num)
{
	int	cnt;
	int	stack_size;

	cnt = 0;
	stack_size = 4;
	while (cnt++ < 2)
	{
		i = 0;
		smallest_num = find_smallest_num_i(a);
		if (smallest_num <= 2)
		{
			while (i++ < smallest_num)
				ra(a, 1);
			pb(a, b);
		}
		else
		{
			while (smallest_num + i++ <= stack_size)
				rra(a, 1);
			pb(a, b);
		}
		stack_size--;
	}
}

void	sort_5(t_stack	**a, t_stack	**b)
{
	t_stack	*tmp;

	tmp = *a;
	sort_5_help(a, b, 0, 0);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
