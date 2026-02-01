/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:37:36 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/01 17:20:53 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list *l;
    if(!lst)
        return(NULL);
    l = lst;
    while (l->next)
    {
        l = l->next;
    }
    return(l);
}

/* #include <stdio.h>
int main()
{
    t_list *head;
    t_list *new = ft_lstnew("E");
    t_list *new2 = ft_lstnew("L");
    t_list *addfr = ft_lstnew("H");
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
    printf("%s", (char *)ft_lstlast(head)->content);
    newtest=head;
    printf("\n-------------------------------------------\n");
    while (newtest)
    {
        printf("%s", (char *)newtest->content);
        newtest=newtest->next;
    }
    return(0);
} */