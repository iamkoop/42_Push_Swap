#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft_lib/libft.h"

typedef struct s_stack
{
    int data;
	int index;
    struct s_stack* next;
    struct s_stack* prev;
} t_stack;

typedef struct s_head
{
    t_stack* first;
    t_stack* last;
} t_head;

void sa(t_stack **a);
void sb(t_stack **b);

#endif