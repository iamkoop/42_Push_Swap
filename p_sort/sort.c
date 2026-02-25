/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 00:05:35 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/25 16:46:28 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_3_help(t_stack **s, int op1, int op2)
{
	if (op1 == 1 || op2 == 1)
		ra(s, 1);
	if (op1 == 2 || op2 == 2)
		rra(s, 1);
	if (op1 == 3 || op2 == 3)
		sa(s, 1);
	return ;
}

void	sort_3(t_stack **s)
{
	int	first;
	int	second;
	int	third;

	first = (*s)->index;
	second = (*s)->next->index;
	third = (*s)->prev->index;
	if (first < second && second < third)
		sort_3_help(s, 0, 0);
	else if (first < second && second > third && third > first)
		sort_3_help(s, 2, 3);
	else if (first > second && second < third && third > first)
		sort_3_help(s, 3, 0);
	else if (first < second && second > third && third < first)
		sort_3_help(s, 2, 0);
	else if (first > second && second < third && third < first)
		sort_3_help(s, 1, 0);
	else if (first > second && second > third)
		sort_3_help(s, 1, 3);
}
