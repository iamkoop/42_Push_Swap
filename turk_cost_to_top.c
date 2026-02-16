/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 22:46:42 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/17 00:34:42 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
static int ft_cctp_help(int a, int b)
{
	printf("a :%d\n", a);
	printf("b :%d\n", b);
	if (a > b)
	{
		return (a);
	}
	else if (a < b)
	{
		return (b);
	}
	else
	{
		return (a);
	}
}

int ft_cttp(int max_a, int max_b, int current_a, int current_b)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (current_a <= max_a / 2)
		a = current_a;
	else if (current_a > max_a / 2)
		a = current_a - max_a;
	if (current_b <= max_b / 2)
		b = current_b;
	else if (current_b > max_b / 2)
		b = current_b - max_b;
	if (a <= 0 && b <= 0)
		return (ft_cctp_help(a * -1, b * -1) + 1);
	else if (a <= 0 && b >= 0)
		return ((a * -1 + 1) + (b + 1));
	else if (a >= 0 && b <= 0)
		return ((a + 1) + (b * -1 + 1));
	else if (a >= 0 && b >= 0)
		return (ft_cctp_help(a, b) + 1);
	else
		return (a + b);
}
#include <stdio.h>
int main(void)
{
	printf("Cost_to_top %d\n", ft_cttp(4, 5, 3, 3));
}
