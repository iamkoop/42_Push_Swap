/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:31:22 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/05 20:40:47 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft_lib/libft.h"


int		input_is_valid(int argc, char **input);
int	**unsorted_and_sorted(char	**input, int argc, int *size);
t_stack	*create_initial_stack(char	**input, int argc);
//int *convert_input_to_arr(int argc, char **argv);
t_stack	*ps_lstnew(int content, int index);
//void sa(t_stack **a);
//void sb(t_stack **b);

#endif