/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:45 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/03 12:46:46 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//-------------------------------------------------------------------------------

/* int main(int argc, char	**argv)
{
	int i = 1;
	
	int *arr = convert_input_to_arr(argc, argv);
	if(!arr)
	{
		free(arr);
		ft_printf("Error");
		return(0);
	}
	while(i < argc)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
	
} */

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		ft_printf("Not enough arguments");
		return(-1);
    }
	if(!input_isValid(argc,argv))
	{
		write(2, "Error\n", 6);
		return(0);
	}
	return(1);
}

