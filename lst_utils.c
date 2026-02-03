/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:08:30 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/02 12:56:15 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstnew(int data)
{
	t_stack *new;
    if(!data)
        return (NULL);
    new = malloc(sizeof(t_list));
    if(!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return(new);
}