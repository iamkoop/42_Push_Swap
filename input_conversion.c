/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:23:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/10 00:25:24 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *convert_input_to_i_arr(char **input, int *size)
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


int **unsorted_and_sorted(int **input, int *size)
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