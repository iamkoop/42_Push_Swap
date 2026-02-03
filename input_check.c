/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:14:03 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/03 17:39:44 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int free_splitted(char **splitted,int ret)
{
	int i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return(ret);
}


static int valid_num(char *str)
{
	int i;

	i = 0;
	if((str[i] == '-') && !str[i + 1])
		return(0);
	if(!ft_isdigit(str[i]) && (str[i] != '-'))
		return(0);
	i++;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return(0);
		i++;	
	}
	return(1);
}

static int valid_num_per_arg(int argc, char **input, int i)
{
	int s;
	char **splitted;

	s = 0;
	while (i < argc && input[i])
	{
		splitted = ft_split(input[i], ' ');
		if(!splitted)
			return(0);
		while (splitted[s])
		{
			if(!valid_num(splitted[s]))
				return(free_splitted(splitted, 0));
			s++;
		}
		if(s != 1)
			return(free_splitted(splitted, 0));
		s = 0;
		free_splitted(splitted,1);
		i++;
	}
	return(1);
}

int input_isValid(int argc, char **input)
{
	int ret;
	char **nums;

	ret = 0;
	if(argc > 2)
	{
		if(!valid_num_per_arg(argc, input, 1))
			return(ret);	
	}
	else if(argc == 2)
	{
		nums = ft_split(input[1], ' ');
		if(!nums)
			return(0);
		ret = valid_num_per_arg(argc, nums, 0);
		free_splitted(nums, 0);
		return(ret);
	}
	return(ret);
}
