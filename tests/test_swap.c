/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity                                  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:15:00 by antigravity       #+#    #+#             */
/*   Updated: 2026/02/09 23:15:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Mocking libft functions here or implementing mini versions to avoid linking
// issues if possible But push_swap.h includes libft.h, so we need to validly
// define t_stack. The structure provided in test_swap.c must match. I will just
// use malloc and basic checks.

t_stack *create_node(int data)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void add_back(t_stack **stack, t_stack *new_node)
{
	t_stack *last;

	if (!stack || !new_node)
		return;
	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

t_stack *build_stack(int *values, int count)
{
	t_stack *stack = NULL;
	int i;
	t_stack *new_node;

	for (i = 0; i < count; i++)
	{
		new_node = create_node(values[i]);
		add_back(&stack, new_node);
	}
	return (stack);
}

void free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void print_stack(t_stack *stack, const char *name)
{
	printf("Stack %s: ", name);
	while (stack)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

int verify_links(t_stack *stack)
{
	if (!stack)
		return (1);
	if (stack->prev != NULL)
	{
		printf("Error: Head prev is not NULL\n");
		return (0);
	}
	while (stack->next)
	{
		if (stack->next->prev != stack)
		{
			printf("Error: Broken link between %d and %d\n", stack->data,
				   stack->next->data);
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int verify_stack_content(t_stack *stack, int *expected, int count)
{
	int i;
	t_stack *curr = stack;

	for (i = 0; i < count; i++)
	{
		if (!curr)
		{
			printf("Error: Stack shorter than expected (idx %d)\n", i);
			return (0);
		}
		if (curr->data != expected[i])
		{
			printf("Error: Value mismatch at idx %d. Expected %d, got %d\n", i,
				   expected[i], curr->data);
			return (0);
		}
		curr = curr->next;
	}
	if (curr)
	{
		printf("Error: Stack longer than expected\n");
		return (0);
	}
	return (1);
}

// Tests

void test_sa(void)
{
	printf("Testing sa...\n");
	// Case 1: 2 elements
	int vals[] = {2, 1};
	t_stack *a = build_stack(vals, 2);
	sa(&a);
	int exp[] = {1, 2};
	if (!verify_stack_content(a, exp, 2))
		printf("FAIL: sa basic swap (content)\n");
	else if (!verify_links(a))
		printf("FAIL: sa basic swap (links)\n");
	else
		printf("PASS: sa basic swap\n");
	free_stack(&a);

	// Case 2: 3 elements
	int vals2[] = {3, 1, 2};
	a = build_stack(vals2, 3);
	sa(&a);
	int exp2[] = {1, 3, 2};
	if (!verify_stack_content(a, exp2, 3))
		printf("FAIL: sa with 3 elements (content)\n");
	else if (!verify_links(a))
		printf("FAIL: sa with 3 elements (links)\n");
	else
		printf("PASS: sa with 3 elements\n");
	free_stack(&a);
}

void test_sb(void)
{
	printf("Testing sb...\n");
	int vals[] = {2, 1};
	t_stack *b = build_stack(vals, 2);
	sb(&b);
	int exp[] = {1, 2};
	if (!verify_stack_content(b, exp, 2))
		printf("FAIL: sb basic swap (content)\n");
	else if (!verify_links(b))
		printf("FAIL: sb basic swap (links)\n");
	else
		printf("PASS: sb basic swap\n");
	free_stack(&b);
}

void test_ss(void)
{
	printf("Testing ss...\n");
	int va[] = {2, 1};
	int vb[] = {4, 3};
	t_stack *a = build_stack(va, 2);
	t_stack *b = build_stack(vb, 2);
	ss(&a, &b);
	int ea[] = {1, 2};
	int eb[] = {3, 4};
	if (!verify_stack_content(a, ea, 2) || !verify_links(a))
		printf("FAIL: ss (stack a)\n");
	else if (!verify_stack_content(b, eb, 2) || !verify_links(b))
		printf("FAIL: ss (stack b)\n");
	else
		printf("PASS: ss\n");
	free_stack(&a);
	free_stack(&b);
}

void test_pa(void)
{
	printf("Testing pa...\n");
	// Setup: A: {3}, B: {2, 1} -> pa -> A: {2, 3}, B: {1}
	int va[] = {3};
	int vb[] = {2, 1};
	t_stack *a = build_stack(va, 1);
	t_stack *b = build_stack(vb, 2);

	pa(&a, &b);

	int ea[] = {2, 3};
	int eb[] = {1};

	if (!verify_stack_content(a, ea, 2) || !verify_links(a))
		printf("FAIL: pa (stack a)\n");
	else if (!verify_stack_content(b, eb, 1) || !verify_links(b))
		printf("FAIL: pa (stack b)\n");
	else
		printf("PASS: pa\n");

	free_stack(&a);
	free_stack(&b);
}

void test_pb(void)
{
	printf("Testing pb...\n");
	// Setup: A: {2, 1}, B: {3} -> pb -> A: {1}, B: {2, 3}
	int va[] = {2, 1};
	int vb[] = {3};
	t_stack *a = build_stack(va, 2);
	t_stack *b = build_stack(vb, 1);

	pb(&a, &b);

	int ea[] = {1};
	int eb[] = {2, 3};

	if (!verify_stack_content(a, ea, 1) || !verify_links(a))
		printf("FAIL: pb (stack a)\n");
	else if (!verify_stack_content(b, eb, 2) || !verify_links(b))
		printf("FAIL: pb (stack b)\n");
	else
		printf("PASS: pb\n");

	free_stack(&a);
	free_stack(&b);
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
