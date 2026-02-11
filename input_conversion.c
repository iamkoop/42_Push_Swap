/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:23:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/11 21:13:12 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr *convert_input_to_i_arr(char **input)
{
	int i;
	int k;
	t_arr *arr;

	arr = malloc(sizeof(t_arr));
	if (!arr)
		return (NULL);
	k = 1;
	i = 1;
	while (input[i])
		i++;
	arr->arr = malloc(sizeof(int) * i);
	if (!arr)
		return (NULL);
	i = 0;
	while (input[k])
	{
		arr->arr[i] = ft_atoi(input[k]);
		i++;
		k++;
	}
	arr->count = k - 1;
	return (arr);
}

int **unsorted_and_sorted(t_arr *arr)
{
	int *unsorted;
	int *sorted;
	int **unsorted_and_sorted;

	unsorted = arr->arr;
	if (!unsorted)
		return (NULL);
	sorted = sorted_arr(unsorted, arr->count);
	if (!sorted)
		return (free(unsorted), NULL);
	unsorted_and_sorted = malloc(sizeof(int *) * 2);
	if (!unsorted_and_sorted)
		return (free(unsorted), free(sorted), NULL);
	unsorted_and_sorted[0] = unsorted;
	unsorted_and_sorted[1] = sorted;
	return (unsorted_and_sorted);
}
