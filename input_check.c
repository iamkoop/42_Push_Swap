/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:14:03 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/03 02:06:06 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static int is_num(char *str)
{
    int i;

    i = 1;

    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return(0);
        i++;
    }
    return(1);
} */

/* static int check_for_dupes(int argc, char **input)
{
	int i;
	int found;

	i = 1;
	found = 1;
	while (i < argc)
	{
		while (found <= i)
		{
                if(found < i && ft_strncmp(input[found], input[i], ft_strlen(input[found]) + 1) == 0)
                    return(0);
			found++;
		}
		found = 1;
		i++;
	}
	return(1);
} */

/* static int check_str_for_multiple_nums(char *str)
{
	char **str;
	
	str = ft_split();
} */

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
	if(!ft_isdigit(str[i]) && str[i] != '-')
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

static int valid_num_per_arg(int argc, char **input)
{
	int i;
	int s;
	char **splitted;

	i = 1;
	s = 0;
	while (i < argc)
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
	int i;
	char **nums;

	i = 0;
	if(argc > 2)
	{
		if(!valid_num_per_arg(argc, input))
			return(0);	
	}
	else if(argc == 2)
	{
		nums = ft_split(input[1], ' ');
		if(!nums)
			return(0);
		while (nums[i])
		{
			printf("%s\n", nums[i]);
			i++;
		}
		printf("%d\n", i);
		return(valid_num_per_arg(i, nums));
	}
	return(0);
}
