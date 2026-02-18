/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 22:46:42 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/18 20:38:58 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_cttp_help_both_same_direction(int a, int b, int *is_max)
{
	if (is_max[0])
		a = 1;
	if (is_max[1])
		b = 1;
	if (a < 0)
		a = a * -1 + 1;
	if (b < 0)
		b = b * -1 + 1;
	if (a == b)
		return (a);
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	else
		return (2147483647);
}
static int ft_cttp_help_diff_direction(int a, int b, int *is_max)
{
	if (a == 0 && b >= 0)
		return (a + b);
	else if (a == 0 && b <= 0)
		return (a + (b * -1 + 1));
	else if (a >= 0 && b == 0)
		return (a + b);
	else if (a <= 0 && b == 0)
		return ((a * -1 + 1) + b);
	else if (a < 0 && b > 0)
		return ((a * -1 + !is_max[0]) + b);
	else if (a > 0 && b < 0)
		return (a + (b * -1 + !is_max[1]));
	return 2147483647;
}
static int is_it_max(int max, int curr)
{
	if (curr == max)
		return (1);
	return (0);
}
int ft_cttp(int max_a, int max_b, int curr_a, int curr_b)
{
	int is_max[2];

	is_max[0] = is_it_max(max_a, curr_a);
	is_max[1] = is_it_max(max_b, curr_b);
	if (curr_a > max_a / 2 && !is_max[0])
		curr_a = curr_a - max_a;
	else if (is_max[0])
		curr_a = -1;
	if (curr_b > max_b / 2 && !is_max[1])
		curr_b = curr_b - max_b;
	else if (is_max[1])
		curr_b = -1;
	if ((curr_a <= 0 && curr_b <= 0) || (curr_a >= 0 && curr_b >= 0))
		return (ft_cttp_help_both_same_direction(curr_a, curr_b, is_max));
	if ((curr_a <= 0 && curr_b >= 0) || (curr_a >= 0 && curr_b <= 0))
		return (ft_cttp_help_diff_direction(curr_a, curr_b, is_max));
	return (2147483647);
}
