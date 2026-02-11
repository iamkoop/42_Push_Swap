/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:43:19 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/11 18:13:36 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_stack **a)
{
	if (!a || !*a || (*a)->next == (*a))
		return;
	*a = (*a)->prev;
	write(1, "rra\n", 4);
}
void rrb(t_stack **b)
{
	if (!b || !*b || (*b)->next == (*b))
		return;
	*b = (*b)->prev;
	write(1, "rrb\n", 4);
}
void rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
