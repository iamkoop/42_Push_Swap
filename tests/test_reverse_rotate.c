/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity                                  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:10:00 by antigravity       #+#    #+#             */
/*   Updated: 2026/02/10 23:10:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_lib/libft.h"
#include "../push_swap.h"

// Prototypes for reverse rotate operations
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

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

void test_rra(void)
{
	ft_printf("\n--- Testing rra ---\n");
	// A: {1, 2, 3} -> rra -> A: {3, 1, 2}
	int vals[] = {1, 2, 3};
	t_stack *a = create_test_stack(vals, 3);
	print_stack(a, "A (Before)");
	rra(&a);
	print_stack(a, "A (After )");
	clear_test_stack(&a);
}

void test_rrb(void)
{
	ft_printf("\n--- Testing rrb ---\n");
	// B: {1, 2, 3} -> rrb -> B: {3, 1, 2}
	int vals[] = {1, 2, 3};
	t_stack *b = create_test_stack(vals, 3);
	print_stack(b, "B (Before)");
	rrb(&b);
	print_stack(b, "B (After )");
	clear_test_stack(&b);
}

void test_rrr(void)
{
	ft_printf("\n--- Testing rrr ---\n");
	// A: {1, 2}, B: {3, 4} -> rrr -> A: {2, 1}, B: {4, 3}
	int va[] = {1, 2};
	int vb[] = {3, 4};
	t_stack *a = create_test_stack(va, 2);
	t_stack *b = create_test_stack(vb, 2);

	print_stack(a, "A (Before)");
	print_stack(b, "B (Before)");

	rrr(&a, &b);

	print_stack(a, "A (After )");
	print_stack(b, "B (After )");

	clear_test_stack(&a);
	clear_test_stack(&b);
}

void test_rra_edge_cases(void)
{
	ft_printf("\n--- Testing rra edge cases ---\n");
	t_stack *a = NULL;
	rra(&a);
	print_stack(a, "A (Empty)");

	int vals[] = {1};
	a = create_test_stack(vals, 1);
	print_stack(a, "A (1 elem)");
	rra(&a);
	print_stack(a, "A (After)");
	clear_test_stack(&a);
}

void test_rrb_edge_cases(void)
{
	ft_printf("\n--- Testing rrb edge cases ---\n");
	t_stack *b = NULL;
	rrb(&b);
	print_stack(b, "B (Empty)");

	int vals[] = {1};
	b = create_test_stack(vals, 1);
	print_stack(b, "B (1 elem)");
	rrb(&b);
	print_stack(b, "B (After)");
	clear_test_stack(&b);
}

void test_rrr_edge_cases(void)
{
	ft_printf("\n--- Testing rrr edge cases ---\n");
	t_stack *a = NULL;
	t_stack *b = NULL;
	rrr(&a, &b);
	print_stack(a, "A (Empty)");
	print_stack(b, "B (Empty)");
}

int main(void)
{
	test_rra();
	test_rrb();
	test_rrr();
	test_rra_edge_cases();
	test_rrb_edge_cases();
	test_rrr_edge_cases();
	return (0);
}
