/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 05:17:36 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/25 16:44:10 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(int argc, t_stack **a, t_stack **b)
{
	if (argc == 2)
		return ;
	else if (argc == 3)
		sa(a, 1);
	else if (argc == 4)
		sort_3(a);
	else if (argc > 4)
		sort_turk(a, b);
}
