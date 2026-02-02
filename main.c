/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:45 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/02 11:50:22 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//-------------------------------------------------------------------------------

t_stack *create_stack(int argc, char **argv, t_head **stack)
{
	int i;

	i = 1;
	(*stack)->first = ft_lstnew(ft_atoi(argv[i]));
	while (i <= argc)
	{
		
		i++;
	}
	
}

int main(int argc, char **argv)
{
	t_list stack_a;
	if(argc < 2)
	{
		ft_printf("Not enough arguments");
		return(-1);
    }
	if(!input_isValid(argc,argv))
	{
		ft_printf("Error\n");
		return(0);
	}
	return(1);
}

