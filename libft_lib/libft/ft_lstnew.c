/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:27:09 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/05 19:05:31 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int content, int index)
{
	t_stack	*new;

	if (!content)
		return (NULL);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = content;
	new->index = index;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

/* #include <stdio.h>
int main()
{
    t_list *head;
    t_list *new = ft_lstnew("H");
    t_list *new2 = ft_lstnew("E");
    t_list *newtest;
    head=new;
    new->next=new2;
    new2->next=NULL;
    newtest = head;  
    while (newtest)
    {
        printf("%s", (char *)newtest->content);
        newtest=newtest->next;
    }
    return(0);
} */