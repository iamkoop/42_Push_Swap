/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:33:43 by nilsdruon         #+#    #+#             */
/*   Updated: 2026/02/01 17:20:59 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *comp;

    comp = *lst;

    while (*lst)
    {
        del(comp->content);
        *lst = comp->next;
        free(comp);
        comp = *lst;
    }
    *lst = NULL;
}

/* #include <stdio.h>
#include <string.h>

void del(void *content)
{
    printf("Deleting content: %s\n", (char *)content);
    free(content);
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_list *lst = NULL;

    ft_lstadd_back(&lst, ft_lstnew(strdup("Hello")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("42")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("Vienna")));

    printf("List before ft_lstclear:\n");
    print_list(lst);

    ft_lstclear(&lst, del);

    printf("\nList after ft_lstclear:\n");
    if (lst == NULL)
        printf("lst is NULL ✅\n");
    else
        printf("lst is NOT NULL ❌\n");

    return 0;
} */