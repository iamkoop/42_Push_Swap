/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:45 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/01 23:12:56 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//-------------------------------------------------------------------------------

int main(int argc, char **argv)
{
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

