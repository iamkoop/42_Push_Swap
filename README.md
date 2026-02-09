# 42_Push_Swap

5 Nums in 12 operations or less
3 in 3
2 in 1

Todo's:
input check ✅
create stack:
-> convert to int array ✅
-> store the sorted array in an extra int array
-> create stack. find location of in the sorted array of the int and write the right index directly

write operations:

write a plan

include and test the checker
antigravity
pdf into the project (doc/folder)


------------------------------------

<!--void test_sa()
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
} */-->