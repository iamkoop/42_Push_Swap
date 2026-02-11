/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity                                  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2026/02/11 02:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_lib/libft.h"
#include "../push_swap.h"

// Prototypes
t_stack *create_test_stack(int *values, int count);
void print_stack(t_stack *stack, char *name);
void clear_test_stack(t_stack **stack);
void sort_3(t_stack **s);

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

void test_permutation(int a, int b, int c)
{
	int vals[] = {a, b, c};
	t_stack *stack = create_test_stack(vals, 3);

	ft_printf("\n--- Test Permutation: %d %d %d ---\n", a, b, c);
	print_stack(stack, "Before");

	// Check if stack is created successfully
	if (!stack)
	{
		ft_printf("Error: Stack creation failed\n");
		return;
	}

	sort_3(&stack);

	print_stack(stack, "After ");
	clear_test_stack(&stack);
}

int main(void)
{
	// 1 2 3 (Already sorted)
	test_permutation(1, 2, 3);

	// 1 3 2
	test_permutation(1, 3, 2);

	// 2 1 3
	test_permutation(2, 1, 3);

	// 2 3 1
	test_permutation(2, 3, 1);

	// 3 1 2
	test_permutation(3, 1, 2);

	// 3 2 1
	test_permutation(3, 2, 1);

	return (0);
}
