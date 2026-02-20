/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:37 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/20 02:47:32 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(t_stack **a, int print)
{
	t_stack *tmp;

	if (!a || !*a || (*a)->next == (*a))
		return;
	if ((*a)->next->next == *a)
	{
		*a = (*a)->next;
	}
	else
	{
		tmp = (*a)->next;
		tmp->next->prev = *a;
		(*a)->prev->next = tmp;
		(*a)->next = tmp->next;
		tmp->prev = (*a)->prev;
		tmp->next = *a;
		(*a)->prev = tmp;
		*a = tmp;
	}
	if (print)
		write(1, "sa\n", 3);
}

void sb(t_stack **b, int print)
{
	t_stack *tmp;

	if (!b || !*b || (*b)->next == (*b))
		return;
	if ((*b)->next->next == *b)
	{
		*b = (*b)->next;
	}
	else
	{
		tmp = (*b)->next;
		tmp->next->prev = *b;
		(*b)->prev->next = tmp;
		(*b)->next = tmp->next;
		tmp->prev = (*b)->prev;
		tmp->next = *b;
		(*b)->prev = tmp;
		*b = tmp;
	}
	if (print)
		write(1, "sb\n", 3);
}
void ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void pa(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (!b || !*b)
		return;
	tmp = *b;
	*b = tmp->next;
	if (tmp->next == tmp)
		*b = NULL;
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	if (!*a)
	{
		*a = tmp;
		tmp->next = *a;
		tmp->prev = *a;
	}
	else
	{
		tmp->prev = (*a)->prev;
		tmp->next = *a;
		(*a)->prev->next = tmp;
		(*a)->prev = tmp;
		*a = (*a)->prev;
	}
	write(1, "pa\n", 3);
}
void pb(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (!b || !*a)
		return;
	tmp = *a;
	*a = tmp->next;
	if (tmp->next == tmp)
		*a = NULL;
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	if (!*b)
	{
		*b = tmp;
		tmp->next = *b;
		tmp->prev = *b;
	}
	else
	{
		tmp->prev = (*b)->prev;
		tmp->next = *b;
		(*b)->prev->next = tmp;
		(*b)->prev = tmp;
		*b = (*b)->prev;
	}
	write(1, "pb\n", 3);
}
