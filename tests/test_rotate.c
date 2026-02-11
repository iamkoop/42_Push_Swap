/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity                                  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:30:00 by antigravity       #+#    #+#             */
/*   Updated: 2026/02/10 21:30:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_lib/libft.h"
#include "../push_swap.h"

// Prototypes for rotate operations
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

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

void test_ra(void)
{
	ft_printf("\n--- Testing ra ---\n");
	// A: {1, 2, 3} -> ra -> A: {2, 3, 1}
	int vals[] = {1, 2, 3};
	t_stack *a = create_test_stack(vals, 3);
	print_stack(a, "A (Before)");
	ra(&a);
	print_stack(a, "A (After )");
	clear_test_stack(&a);
}

void test_rb(void)
{
	ft_printf("\n--- Testing rb ---\n");
	// B: {1, 2, 3} -> rb -> B: {2, 3, 1}
	int vals[] = {1, 2, 3};
	t_stack *b = create_test_stack(vals, 3);
	print_stack(b, "B (Before)");
	rb(&b);
	print_stack(b, "B (After )");
	clear_test_stack(&b);
}

void test_rr(void)
{
	ft_printf("\n--- Testing rr ---\n");
	// A: {1, 2}, B: {3, 4} -> rr -> A: {2, 1}, B: {4, 3}
	int va[] = {1, 2};
	int vb[] = {3, 4};
	t_stack *a = create_test_stack(va, 2);
	t_stack *b = create_test_stack(vb, 2);

	print_stack(a, "A (Before)");
	print_stack(b, "B (Before)");

	rr(&a, &b);

	print_stack(a, "A (After )");
	print_stack(b, "B (After )");

	clear_test_stack(&a);
	clear_test_stack(&b);
}

void test_ra_edge_cases(void)
{
	ft_printf("\n--- Testing ra edge cases ---\n");
	t_stack *a = NULL;
	ra(&a);
	print_stack(a, "A (Empty)");

	int vals[] = {1};
	a = create_test_stack(vals, 1);
	print_stack(a, "A (1 elem)");
	ra(&a);
	print_stack(a, "A (After)");
	clear_test_stack(&a);
}

void test_rb_edge_cases(void)
{
	ft_printf("\n--- Testing rb edge cases ---\n");
	t_stack *b = NULL;
	rb(&b);
	print_stack(b, "B (Empty)");

	int vals[] = {1};
	b = create_test_stack(vals, 1);
	print_stack(b, "B (1 elem)");
	rb(&b);
	print_stack(b, "B (After)");
	clear_test_stack(&b);
}

void test_rr_edge_cases(void)
{
	ft_printf("\n--- Testing rr edge cases ---\n");
	t_stack *a = NULL;
	t_stack *b = NULL;
	rr(&a, &b);
	print_stack(a, "A (Empty)");
	print_stack(b, "B (Empty)");
}

int main(void)
{
	test_ra();
	test_rb();
	test_rr();
	test_ra_edge_cases();
	test_rb_edge_cases();
	test_rr_edge_cases();
	return (0);
}
