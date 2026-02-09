/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:14:03 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/09 23:07:55 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int inputs(char **splitted, int ret)
{
	int i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (ret);
}

static int valid_num(char *str)
{
	int i;
	long num;

	i = 0;
	if ((str[i] == '-') && !str[i + 1])
		return (0);
	if (!ft_isdigit(str[i]) && (str[i] != '-'))
		return (0);
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atol(str);
	if ((num > 2147483647) || (num < -2147483648))
		return (0);
	return (1);
}

static int valid_num_per_arg(char **input)
{
	int i;
	int s;
	char **splitted;

	i = 1;
	s = 0;
	while (input[i])
	{
		splitted = ft_split(input[i], ' ');
		if (!splitted)
			return (0);
		while (splitted[s])
		{
			if (!valid_num(splitted[s]))
				return (inputs(splitted, 0));
			s++;
		}
		if (s != 1)
			return (inputs(splitted, 0));
		s = 0;
		inputs(splitted, 1);
		i++;
	}
	return (1);
}

static int duplicates(char **input, int ret)
{
	int i;
	int k;
	int num_to_cmp_with;
	int curr_num;

	if (!ret)
		return (0);
	i = 0;
	while (input[i])
	{
		num_to_cmp_with = ft_atoi(input[i]);
		k = 0;
		while (i > 0 && k < i)
		{
			curr_num = ft_atoi(input[k]);
			if (curr_num == num_to_cmp_with)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int input_is_valid(char **input)
{
	int ret;

	ret = duplicates(input, valid_num_per_arg(input));
	return (ret);
}
