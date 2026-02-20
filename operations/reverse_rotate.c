/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:43:19 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/20 02:44:04 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_stack **a, int print)
{
	if (!a || !*a || (*a)->next == (*a))
		return;
	*a = (*a)->prev;
	if (print)
		write(1, "rra\n", 4);
}
void rrb(t_stack **b, int print)
{
	if (!b || !*b || (*b)->next == (*b))
		return;
	*b = (*b)->prev;
	if (print)
		write(1, "rrb\n", 4);
}
void rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
