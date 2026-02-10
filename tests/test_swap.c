/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity                                  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:35:00 by antigravity       #+#    #+#             */
/*   Updated: 2026/02/10 01:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_lib/libft.h"
#include "../push_swap.h"

// Prototypes for swap operations
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);

t_stack *create_test_stack(int *values, int count)
{
	t_arr input_arr;
	t_stack *stack;
	int i;

	input_arr.count = count;
	input_arr.arr = malloc(sizeof(int) * count);
	if (!input_arr.arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		input_arr.arr[i] = values[i];
		i++;
	}
	stack = create_initial_stack(&input_arr);
	free(input_arr.arr);
	return (stack);
}

void print_stack(t_stack *stack, char *name)
{
	t_stack *curr;

	ft_printf("Stack %s: ", name);
	if (!stack)
	{
		ft_printf("(empty)\n");
		return;
	}
	curr = stack;
	do
	{
		ft_printf("%d ", curr->data);
		curr = curr->next;
	} while (curr != stack);
	ft_printf("\n");
}

/*
   We using ft_lstclear but we need to be careful with circular lists.
   The project's stack is circular. ft_lstclear usually expects NULL
   termination. However, since we are just testing, let's break the circle
   before clearing if needed, or just write a simple clear for circular.
   Actually, let's just use a simple manual text clear to avoid issues if
   ft_lstclear isn't adapted.
*/
void clear_test_stack(t_stack **stack)
{
	t_stack *curr;
	t_stack *tmp;
	t_stack *head;

	if (!stack || !*stack)
		return;
	head = *stack;
	curr = head;
	while (curr->next != head)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	free(curr);
	*stack = NULL;
}

void test_sa(void)
{
	ft_printf("\n--- Testing sa ---\n");
	int vals[] = {2, 1};
	t_stack *a = create_test_stack(vals, 2);
	print_stack(a, "A (Before)");
	sa(&a);
	print_stack(a, "A (After )");
	clear_test_stack(&a);
}

void test_sb(void)
{
	ft_printf("\n--- Testing sb ---\n");
	int vals[] = {2, 1};
	t_stack *b = create_test_stack(vals, 2);
	print_stack(b, "B (Before)");
	sb(&b);
	print_stack(b, "B (After )");
	clear_test_stack(&b);
}

void test_ss(void)
{
	ft_printf("\n--- Testing ss ---\n");
	int va[] = {2, 1};
	int vb[] = {4, 3};
	t_stack *a = create_test_stack(va, 2);
	t_stack *b = create_test_stack(vb, 2);

	print_stack(a, "A (Before)");
	print_stack(b, "B (Before)");
	ss(&a, &b);
	print_stack(a, "A (After )");
	print_stack(b, "B (After )");

	clear_test_stack(&a);
	clear_test_stack(&b);
}

void test_pa(void)
{
	ft_printf("\n--- Testing pa ---\n");
	// A: {3}, B: {2, 1} -> pa -> A: {2, 3}, B: {1}
	int va[] = {3};
	int vb[] = {2, 1};
	t_stack *a = create_test_stack(va, 1);
	t_stack *b = create_test_stack(vb, 2);

	print_stack(a, "A (Before)");
	print_stack(b, "B (Before)");

	pa(&a, &b);

	print_stack(a, "A (After )");
	print_stack(b, "B (After )");

	clear_test_stack(&a);
	clear_test_stack(&b);
}

void test_pb(void)
{
	ft_printf("\n--- Testing pb ---\n");
	// A: {2, 1}, B: {3} -> pb -> A: {1}, B: {2, 3}
	int va[] = {2, 1};
	int vb[] = {3};
	t_stack *a = create_test_stack(va, 2);
	t_stack *b = create_test_stack(vb, 1);

	print_stack(a, "A (Before)");
	print_stack(b, "B (Before)");

	pb(&a, &b);

	print_stack(a, "A (After )");
	print_stack(b, "B (After )");

	clear_test_stack(&a);
	clear_test_stack(&b);
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
