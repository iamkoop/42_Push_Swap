/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:43:19 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/10 23:32:40 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_stack **a)
{
	if (!a || !*a || (*a)->next == (*a))
		return;
	*a = (*a)->prev;
}
void rrb(t_stack **b)
{
	if (!b || !*b || (*b)->next == (*b))
		return;
	*b = (*b)->prev;
}
void rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
