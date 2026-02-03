/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:23:47 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/02 18:58:54 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void	contains_multiple_nums(char *str, int *flag, int *index, int *wordc)
{
	int	i;

	i = 0;
	
	while (str[i])
	{
		if (str[i] == ' ')
		{
			*flag = 1;
			*index = 0;
			return ;
		}
		i++;
	}
}

int	*convert_input_to_arr(int argc, char **argv)
{
	int		*arr;
	int		i;
	int		flag;
	char	**str;

	i = 1;
	flag = 0;
	arr = malloc(sizeof(int) * argc - 1);
	if (!arr)
		return (NULL);
	contains_multiple_nums(argv[1], &flag, &i);
	str = ft_split(argv[1], ' ');
	if (!str)
		return (NULL);
	while (i < argc)
	{
		if (!flag)
			arr[i] = ft_atoi(argv[i]);
		else
		{
			printf("pos: %d, %d\n", i,ft_atoi(str[i]));
			arr[i] = ft_atoi(str[i]);	
		}
		
		i++;
	}
	if (flag)
		free(str); 
	return (arr);
}*/
