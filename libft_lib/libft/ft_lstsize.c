/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:27:16 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/01 20:50:37 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;
    
    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return(i);
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
    printf("\n");
    printf("%d", ft_lstsize(NULL));
    printf("\n");
    return(0);
} */