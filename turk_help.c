/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:18:34 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/20 03:27:11 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void save_new_cttp(int curr_a, int curr_b, int cttp, t_o_p **smlst_m_n)
{
	(*smlst_m_n)->loc_a = curr_a;
	(*smlst_m_n)->loc_b = curr_b;
	(*smlst_m_n)->total_cost = cttp;
}

static void f_s_op_help(t_stack *a, t_stack **b, int m_a, t_o_p **smlst_m_n)
{
	t_stack *cur_b;
	// int stack_a[2];
	int cttp;

	cur_b = *b;
	while (1)
	{
		if ((a->index < cur_b->index && cur_b->index < a->next->index) ||
			((a->index > a->next->index) &&
			 (cur_b->index > a->index || cur_b->index < a->next->index)))
		{
			cttp = ft_cttp(m_a, (*b)->prev->curr_i, a->next->curr_i,
						   cur_b->curr_i);
			if (cttp < (*smlst_m_n)->total_cost)
				save_new_cttp(a->next->curr_i, cur_b->curr_i, cttp, smlst_m_n);
		}
		cur_b = cur_b->next;
		if (cur_b == *b)
			break;
	}
}

static void find_smllst_op(t_stack **a, t_stack **b, t_o_p **smlst_m_n)
{
	t_stack *curr_a;

	curr_a = *a;
	while (1)
	{
		f_s_op_help(curr_a, b, (*a)->prev->curr_i, smlst_m_n);
		curr_a = curr_a->next;
		if (curr_a == *a)
			break;
	}
}

void find_smallest_op_and_exec(t_stack **a, t_stack **b)
{
	t_o_p *least_num_of_moves;

	least_num_of_moves = malloc(sizeof(t_o_p));
	if (!least_num_of_moves)
	{
		write(2, "Error\n", 6);
		return;
	}
	least_num_of_moves->total_cost = 2147483647;
	least_num_of_moves->loc_a = 2147483647;
	least_num_of_moves->loc_b = 2147483647;
	find_smllst_op(a, b, &least_num_of_moves);
	if (least_num_of_moves->total_cost != 0)
		exec_op(a, b, least_num_of_moves);
	pa(a, b);
	free(least_num_of_moves);
}
