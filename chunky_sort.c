/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunky_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:54:34 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/16 23:11:42 by ssottori         ###   ########.fr       */
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

int	partition(int *pivot, int *stack, int size)
{
	int	i;
	int	j;
	int *tmp;

	tmp = (int *)malloc(sizeof(int *
