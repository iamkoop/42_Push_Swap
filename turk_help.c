/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:18:34 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/16 00:12:08 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// sso: save smallest operation
static void sso(t_stack *a, t_stack *b, t_optimal_p **cttop, int new_ctt)
{
	(*cttop)->position_a = a->curr_i;
	(*cttop)->position_b = b->curr_i;
	(*cttop)->moves = new_ctt;
}

/*static void execute_moves()
{
}*/

// must be between current num and next (most cost efficient out of those)
static void find_smallest_op(t_stack **a, t_stack **b, t_optimal_p **ctt)
{
	t_stack *s_a;
	t_stack *s_b;
	int new_ctt;

	s_a = *a;
	s_b = *b;

	while (s_a->curr_i <= (*a)->prev->curr_i)
	{
		while (s_b->curr_i <= (*b)->prev->curr_i)
		{
			if (s_b->curr_i < s_a->curr_i && s_b->curr_i < s_a->next->curr_i)
			{
				(*ctt)->curr_position_a = s_a->curr_i;
				(*ctt)->curr_position_b = s_b->curr_i;
				new_ctt = ft_cttp((*a)->prev->curr_i, (*b)->prev->curr_i, ctt);
				if (new_ctt < (*ctt)->moves)
					sso(s_a, s_b, ctt, new_ctt);
			}
			s_b = s_b->next;
		}
		s_a = s_a->next;
	}
}

void find_smallest_op_and_exec(t_stack **a, t_stack **b)
{
	t_optimal_p *least_num_of_moves;

	least_num_of_moves = malloc(sizeof(t_optimal_p));
	if (!least_num_of_moves)
	{
		write(2, "Error\n", 6);
		return;
	}
	least_num_of_moves->moves = 2147483647;
	find_smallest_op(a, b, &least_num_of_moves);
}
