/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:27:32 by nildruon          #+#    #+#             */
/*   Updated: 2026/01/23 16:44:37 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>
//-------------------------------------------------------------------------------

t_stack *ft_lstnew(int content)
{
    t_stack *new;
    new = malloc(sizeof(t_stack));
    if(!new)
        return (NULL);
    new->data = content;
    new->next = NULL;
    return(new);
}
//-------------------------------------------------------------------------------

int main(void)
{
	printf("Testing func sa:");
	test_sa();
}

void test_sa()
{
	t_stack *head;
    t_stack *new = ft_lstnew((int)3);
    t_stack *new2 = ft_lstnew((int)2);
    t_stack *new3 = ft_lstnew((int)5);
    t_stack *newtest;
    head=new;
    new->next=new2;
    new2->next=new3;
	new3->next=NULL;
    newtest = head;  
    while (newtest)
    {
        printf("%d\n", (int)newtest->data);
        newtest=newtest->next;
    }
    printf("\n-------------------------------------------\n");
	sb(&head);
	newtest = head;
    while (newtest)
    {
        printf("%d\n", (int)newtest->data);
        newtest=newtest->next;
    }
}

/*


#include <stdio.h>
int main()
{
    t_stack *head;
    t_stack *new = ft_lstnew((int)3);
    t_stack *new2 = ft_lstnew((int)2);
    t_stack *new3 = ft_lstnew((int)5);
    t_stack *newtest;
    head=new;
    new->next=new2;
    new2->next=new3;
	new3->next=NULL;
    newtest = head;  
    while (newtest)
    {
        printf("%d\n", (int)newtest->data);
        newtest=newtest->next;
    }
    printf("\n-------------------------------------------\n");
	sb(&head);
	newtest = head;
    while (newtest)
    {
        printf("%d\n", (int)newtest->data);
        newtest=newtest->next;
    }
    return(0);
}

#include <stdio.h>
int main()
{
    t_stack *head_a;
    t_stack *new_a = ft_lstnew((int)3);
    t_stack *new2_a = ft_lstnew((int)2);
    t_stack *new3_a = ft_lstnew((int)5);
    t_stack *newtest_a;
//-------------------------------------------------------------------------------
    head_a=new_a;
    new_a->next = new2_a;
    new2_a->next = new3_a;
	new3_a->next=NULL;
    newtest_a = head_a;
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
    while (newtest)
    {
        printf("%d\n", (int)newtest->data);
        newtest=newtest->next;
    }
    printf("\n-------------------------------------------\n");
	sb(&head);
	newtest = head;
    while (newtest)
    {
        printf("%d\n", (int)newtest->data);
        newtest=newtest->next;
    }
    return(0);
} */