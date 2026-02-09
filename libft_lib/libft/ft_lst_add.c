/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:35:38 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/09 20:30:52 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd(t_stack **lst, t_stack *new_node)
{
	new_node->next = *lst;
	new_node->prev = (*lst)->prev;
	(*lst)->prev->next = new_node;
	(*lst)->prev = new_node;
}
