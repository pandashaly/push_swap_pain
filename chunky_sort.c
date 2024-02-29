/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunky_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:54:34 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/16 16:42:56 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quicksort_a(t_stack *stack, int size, int rotate_count)
{
	int	pivot;
	int	numbers;

	if (stack_sorted(stack->a, size) == 1)
		return (1);
	numbers = size;
	if (size <= 3)
	{
		quicksort_3_a_b(stack, size);
		return (1);
	}
	if (!rotate_count && !partition(&pivot, stack->a, size))
		return (0);
	while (size != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < pivot && (size--))
			pb(stack);
		else if (++rotate_count)
			ra(stack);
	}
	while (rotate_count--)
		rra(stack);
	return (quicksort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stack, numbers / 2, 0));
	return (1);
}

int	quicksort_b(t_stack *stack, int size, int rotate_count)
{
	int	pivot;
	int	numbers;

	if (!rotate_count && stack_sorted_desc(stack->b, size) == 1)
		while (size--)
			pa(stack);
	if (size <= 3)
	{
		smol_sort_b(stack, size);
		return (1);
	}
	numbers = size;
	if (!partition(&pivot, stack->b, dim))
		return (0);
	while (size != numbers / 2)
	{
		if (stack->b[0] >= pivot && size--)
			pa(stack);
		else if (++rotate_count)
			rb(stack);
	}
	while (numbers / 2 != stack->last_b && rotate_count--)
		rrb(stack);
	return (quicksort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stack, numbers / 2, 0));
}

int	partition(int *pivot, int *stack, int size)
{
	int	i;
	int	j;
	int 	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (i < size)
		tmp[j++] = stack[i++];
	tmp_sort(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}

void	qs_3ab(t_stack *stack, int size)
{
	if (size == 3 && stack->last_a == 3)
		smol_sort(stack);
	else if (size == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
	else if (size == 3)
	{
		while (size != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (size == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack);
			else if (size == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				size = push_pop(stack, dim, 1);
			else if (stack->a[0] > stack->a[1])
				sa(stack);
			else if (size++)
				pa(stack);
		}
	}
}
