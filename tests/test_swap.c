/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity                                  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:35:00 by antigravity       #+#    #+#             */
/*   Updated: 2026/02/09 23:35:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Prototypes for swap operations
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);

// Helper to build circular stack using libft
// ft_lstadd inserts before head in circular list?
// Based on ft_lst_add.c:
// new->next = *lst; new->prev = (*lst)->prev; (*lst)->prev->next = new;
// (*lst)->prev = new; This inserts 'new' at the end of the list (before head).
t_stack *build_stack_circular(int *values, int count)
{
	t_stack *stack = NULL;
	t_stack *new_node;
	int i;

	for (i = 0; i < count; i++)
	{
		new_node = ft_lstnew(values[i], 0);
		if (!new_node)
			return (NULL); // Should free previous... ignoring for test
						   // simplicity or calling clear

		if (!stack)
		{
			stack = new_node;
			stack->next = stack;
			stack->prev = stack;
		}
		else
		{
			ft_lstadd(&stack, new_node);
		}
	}
	return (stack);
}

void print_stack(t_stack *stack, const char *name)
{
	t_stack *curr;

	printf("Stack %s: ", name);
	if (!stack)
	{
		printf("(empty)\n");
		return;
	}
	curr = stack;
	do
	{
		printf("%d ", curr->data);
		curr = curr->next;
	} while (curr != stack);
	printf("\n");
}

int verify_circular_links(t_stack *stack)
{
	t_stack *curr;

	if (!stack)
		return (1);
	curr = stack;
	do
	{
		if (curr->next->prev != curr)
		{
			printf("Error: Broken forward/backward link at %d\n", curr->data);
			return (0);
		}
		if (curr->prev->next != curr)
		{
			printf("Error: Broken backward/forward link at %d\n", curr->data);
			return (0);
		}
		curr = curr->next;
	} while (curr != stack);
	return (1);
}

int verify_stack_content(t_stack *stack, int *expected, int count)
{
	t_stack *curr;
	int i;

	if (count == 0)
	{
		if (stack)
		{
			printf("Error: Expected empty stack, but it is not.\n");
			return (0);
		}
		return (1);
	}
	if (!stack)
	{
		printf("Error: Stack is empty, expected %d elements.\n", count);
		return (0);
	}
	curr = stack;
	for (i = 0; i < count; i++)
	{
		if (curr->data != expected[i])
		{
			printf("Error: Value mismatch at idx %d. Expected %d, got %d\n", i,
				   expected[i], curr->data);
			return (0);
		}
		curr = curr->next;
		if (curr == stack && i < count - 1)
		{
			printf(
				"Error: Stack shorter than expected (looped early at idx %d)\n",
				i);
			return (0);
		}
	}
	if (curr != stack)
	{
		printf("Error: Stack longer than expected\n");
		return (0);
	}
	return (1);
}

// Helper to free circular stack
void clear_stack(t_stack **stack)
{
	t_stack *curr;
	t_stack *tmp;
	t_stack *head;

	if (!stack || !*stack)
		return;
	head = *stack;
	curr = head;
	// Break valid circularity to avoid modifying ft_lstclear if it relies on
	// NULLs? But ft_lstclear (if standard) relies on NULL. Since we built it
	// manually, we should free it manually. We can loop until we hit head.

	// Assuming ft_lstclear works on NULL terminated.
	// Let's just free manually node by node.

	// Break the circle first to behave like a linear list?
	// Or just iterate once.

	// Safer manual free:
	curr = head;
	while (curr->next != head)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	free(curr); // Free last node
	*stack = NULL;
}

void test_sa(void)
{
	printf("Testing sa...\n");
	int vals[] = {2, 1};
	t_stack *a = build_stack_circular(vals, 2);
	sa(&a);
	int exp[] = {1, 2};
	if (!verify_stack_content(a, exp, 2) || !verify_circular_links(a))
		printf("FAIL: sa basic swap\n");
	else
		printf("PASS: sa basic swap\n");
	clear_stack(&a);
}

void test_sb(void)
{
	printf("Testing sb...\n");
	int vals[] = {2, 1};
	t_stack *b = build_stack_circular(vals, 2);
	sb(&b);
	int exp[] = {1, 2};
	if (!verify_stack_content(b, exp, 2) || !verify_circular_links(b))
		printf("FAIL: sb basic swap\n");
	else
		printf("PASS: sb basic swap\n");
	clear_stack(&b);
}

void test_ss(void)
{
	printf("Testing ss...\n");
	int va[] = {2, 1};
	int vb[] = {4, 3};
	t_stack *a = build_stack_circular(va, 2);
	t_stack *b = build_stack_circular(vb, 2);
	ss(&a, &b);
	int ea[] = {1, 2};
	int eb[] = {3, 4};
	if (!verify_stack_content(a, ea, 2) || !verify_circular_links(a))
		printf("FAIL: ss (stack a)\n");
	else if (!verify_stack_content(b, eb, 2) || !verify_circular_links(b))
		printf("FAIL: ss (stack b)\n");
	else
		printf("PASS: ss\n");
	clear_stack(&a);
	clear_stack(&b);
}

void test_pa(void)
{
	printf("Testing pa...\n");
	// A: {3}, B: {2, 1} -> pa -> A: {2, 3}, B: {1}
	int va[] = {3};
	int vb[] = {2, 1};
	t_stack *a = build_stack_circular(va, 1);
	t_stack *b = build_stack_circular(vb, 2);

	pa(&a, &b);

	int ea[] = {2, 3};
	int eb[] = {1};

	if (!verify_stack_content(a, ea, 2) || !verify_circular_links(a))
	{
		printf("FAIL: pa (stack a)\n");
		print_stack(a, "A");
	}
	else if (!verify_stack_content(b, eb, 1) || !verify_circular_links(b))
	{
		printf("FAIL: pa (stack b)\n");
		print_stack(b, "B");
	}
	else
		printf("PASS: pa\n");

	clear_stack(&a);
	clear_stack(&b);
}

void test_pb(void)
{
	printf("Testing pb...\n");
	// A: {2, 1}, B: {3} -> pb -> A: {1}, B: {2, 3}
	int va[] = {2, 1};
	int vb[] = {3};
	t_stack *a = build_stack_circular(va, 2);
	t_stack *b = build_stack_circular(vb, 1);

	pb(&a, &b);

	int ea[] = {1};
	int eb[] = {2, 3};

	if (!verify_stack_content(a, ea, 1) || !verify_circular_links(a))
	{
		printf("FAIL: pb (stack a)\n");
		print_stack(a, "A");
	}
	else if (!verify_stack_content(b, eb, 2) || !verify_circular_links(b))
	{
		printf("FAIL: pb (stack b)\n");
		print_stack(b, "B");
	}
	else
		printf("PASS: pb\n");

	clear_stack(&a);
	clear_stack(&b);
}

int main(void)
{
	test_sa();
	test_sb();
	test_ss();
	test_pa();
	test_pb();
	return (0);
}
