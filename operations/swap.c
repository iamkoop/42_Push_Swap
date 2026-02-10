/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:37 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/10 02:09:40 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(t_stack **a)
{
	t_stack *tmp;

	if (!a || (*a)->next == NULL)
		return;
	tmp = (*a)->next;
	tmp->prev = (*a)->prev;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a)->prev = tmp;
}

void sb(t_stack *b)
{
	t_stack *temp;

	if (!b || b->next == NULL)
		return;
	temp = b;
	b = b->next;
	temp->next = b->next;
	b->next = temp;
}
void ss(t_stack *a, t_stack *b)
{
	sa(&a);
	sb(b);
}

void pa(t_stack *a, t_stack *b)
{
	t_stack *tmp;
	t_stack *node;
	if (!b)
		return;
	node = b;
	tmp = b->next;
	b->prev->next = b->next;
	b->next->prev = b->prev;
	b = tmp;
	node->prev = a->prev;
	a->prev->next = node;
	node->next = a;
	a->prev = node;
	a = node;
}
void pb(t_stack *a, t_stack *b)
{
	t_stack *tmp;
	t_stack *node;
	if (!a)
		return;
	node = a;
	tmp = a->next;
	a->prev->next = a->next;
	a->next->prev = a->prev;
	a = tmp;
	node->prev = b->prev;
	b->prev->next = node;
	node->next = b;
	b->prev = node;
	b = node;
}
