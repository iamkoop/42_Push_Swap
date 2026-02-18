/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:18:34 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/18 20:42:28 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void save_new_cttp(int curr_a, int curr_b, int cttp, t_o_p **smlst_m_n)
{
	(*smlst_m_n)->location_a = curr_a;
	(*smlst_m_n)->location_b = curr_b;
	(*smlst_m_n)->total_cost = cttp;
}

static void f_s_op_help(t_stack *a, t_stack **b, int max_a, t_o_p **smlst_m_n)
{
	t_stack *curr_b;
	// int stack_a[2];
	int cttp;

	curr_b = *b;
	while (1)
	{
		cttp = ft_cttp(max_a, (*b)->prev->curr_i, a->curr_i, curr_b->curr_i);
		if (cttp < (*smlst_m_n)->total_cost)
			save_new_cttp(a->curr_i, curr_b->curr_i, cttp, smlst_m_n);
		curr_b = curr_b->next;
		if (curr_b == *b)
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

/*static void exec_op(t_stack **a, t_stack **b, t_o_p *least_num_of_moves)
{
}*/

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
	least_num_of_moves->location_a = 2147483647;
	least_num_of_moves->location_b = 2147483647;
	find_smllst_op(a, b, &least_num_of_moves);
	// exec_op();
}
