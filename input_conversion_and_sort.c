/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_conversion_and_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:23:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/09 22:58:42 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void selection_sort(int *arr, int size)
{
	int a;
	int b;
	int smallest;
	int temp;

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

static int *sorted_arr(int *arr, int size)
{
	int *ret;
	int i;

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

static int *convert_input_to_i_arr(char **input, int *size)
{
	int i;
	int k;
	int *arr;

	k = 1;
	i = 1;
	while (input[i])
		i++;
	arr = malloc(sizeof(int) * i);
	if (!arr)
		return (NULL);
	i = 0;
	while (input[k])
	{
		arr[i] = ft_atoi(input[k]);
		i++;
		k++;
	}
	*size = k - 1;
	return (arr);
}

int **unsorted_and_sorted(char **input, int *size)
{
	int *unsorted;
	int *sorted;
	int **unsorted_and_sorted;

	unsorted = NULL;
	unsorted = convert_input_to_i_arr(input, size);
	if (!unsorted)
		return (NULL);
	sorted = sorted_arr(unsorted, *size);
	if (!sorted)
		return (free(unsorted), NULL);
	unsorted_and_sorted = malloc(sizeof(int *) * 2);
	if (!unsorted_and_sorted)
		return (free(unsorted), free(sorted), NULL);
	unsorted_and_sorted[0] = unsorted;
	unsorted_and_sorted[1] = sorted;
	return (unsorted_and_sorted);
}
