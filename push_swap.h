#include <stdlib.h>
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
