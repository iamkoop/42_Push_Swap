/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:14:03 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/01 23:12:43 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_num(char *str)
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
}

int input_isValid(int argc, char **input)
{
	int i;
	int found;

	i = 1;
	found = 1;
	while (i < argc)
	{
		if(!is_num(input[i]))
			return(0);
		while (found <= i)
		{
            if(ft_strlen(input[found]) == ft_strlen(input[i]))
            {
                if(found < i && ft_strncmp(input[found], input[i], ft_strlen(input[i])) == 0)
                    return(0);
            }
			found++;
		}
		found = 0;
		i++;
	}
	return(1);
}