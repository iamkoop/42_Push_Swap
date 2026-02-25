/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:05:49 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/25 16:50:34 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	selection_sort(int *arr, int size)
{
	int	a;
	int	b;
	int	smallest;
	int	temp;

	a = 0;
	smallest = 0;
	temp = 0;
	while (a < size)
	{
		b = a;
		smallest = b;
		while (b < size)
		{
			if (arr[b] < arr[smallest])
				smallest = b;
			b++;
		}
		temp = arr[a];
		arr[a] = arr[smallest];
		arr[smallest] = temp;
		a++;
	}
}

int	*sorted_arr(int *arr, int size)
{
	int	*ret;
	int	i;

	i = 0;
	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = arr[i];
		i++;
	}
	selection_sort(ret, size);
	return (ret);
}
