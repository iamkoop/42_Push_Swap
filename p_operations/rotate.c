/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:41 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/20 05:40:59 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a, int print)
{
	if (!a || !*a || (*a)->next == (*a))
		return ;
	*a = (*a)->next;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	if (!b || !*b || (*b)->next == (*b))
		return ;
	*b = (*b)->next;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
