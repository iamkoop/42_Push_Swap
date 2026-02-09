/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_conversion_and_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:23:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/07 16:24:56 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	*sorted_arr(int *arr, int size)
{
	int *ret;
	int i;
	
	i = 0;
	ret = malloc(sizeof(int) * size);
	if(!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = arr[i];
		i++;
	}
	selection_sort(ret, size);
	return (ret);
}

static int *convert_input_to_i_arr(char **input, int k, int *size)
{
	int i;
	int *arr;

	i = k;
	while (input[i])
		i++;
	arr = malloc(sizeof(int) * i);
	if(!arr)
		return(NULL);
	i = 0;
	while (input[k])
	{
		arr[i] = ft_atoi(input[k]);
		i++;
		k++;
	}
	*size = k;
	return (arr);
}

static int **free_and_return(int *arr, int **unsorted_and_sorted, char **nums)
{
	int i;

	i = 0;
	if(arr)
		free(arr);
	if(unsorted_and_sorted)
		free(unsorted_and_sorted);
	if(nums)
	{
		while(nums[i])
		{
			free(nums[i]);
			i++;
		}
		free(nums);
	}
	return (NULL);
}

int	**unsorted_and_sorted(char	**input, int argc, int *size)
{
	int *arr;
	char **nums;
	int *sorted;
	int **unsorted_and_sorted;
	
	arr = NULL;
	nums = NULL;
	if(argc > 2)
		arr = convert_input_to_i_arr(input, 0, size);
	else if(argc == 2)
	{
		nums = ft_split(input[1], ' ');
		if(!nums)
			return (NULL);
		arr = convert_input_to_i_arr(nums, 0, size);
	}
	unsorted_and_sorted = malloc(sizeof(int*) * 2);
	if(!arr || !unsorted_and_sorted || !nums)
		return (free_and_return(arr, unsorted_and_sorted, nums));
	sorted = sorted_arr(arr, *size);
	if(!sorted)
		return (NULL);
	unsorted_and_sorted[0] = arr;
	unsorted_and_sorted[1] = sorted;
	return(unsorted_and_sorted);
}
