/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:35:38 by nildruon          #+#    #+#             */
/*   Updated: 2026/02/05 21:16:02 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	new->prev = (*lst)->prev;
	
	(*lst)->prev->next = new;
	(*lst)->prev = new;
}