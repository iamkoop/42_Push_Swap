/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:41 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/11 18:12:58 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(t_stack **a)
{
	if (!a || !*a || (*a)->next == (*a))
		return;
	*a = (*a)->next;
	write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
	if (!b || !*b || (*b)->next == (*b))
		return;
	*b = (*b)->next;
	write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
