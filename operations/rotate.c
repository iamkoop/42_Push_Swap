/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:41 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/11 00:04:00 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(t_stack **a)
{
	if (!a || !*a || (*a)->next == (*a))
		return;
	*a = (*a)->next;
}

void rb(t_stack **b)
{
	if (!b || !*b || (*b)->next == (*b))
		return;
	*b = (*b)->next;
}

void rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
