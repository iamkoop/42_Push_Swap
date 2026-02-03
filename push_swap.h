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

int input_isValid(int argc, char **input);
int *convert_input_to_arr(int argc, char **argv);
t_stack	*ps_lstnew(int content);
void sa(t_stack **a);
void sb(t_stack **b);

#endif