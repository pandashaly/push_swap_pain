/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_brain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:14:30 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/15 21:14:52 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i - 1] > stack[i])
			return (false);
		i++;
	}
	return (true);
}

bool	stack_sorted_desc(int *stack, int size)
{
	int	i;

	i = 1;
	while (1 < size)
	{
		if (stack[i - 1] < stack[i])
			return (false);
		i++;
	}
	return (true);
}

int	push_pop(t_stack *stack, int size, int flag)
{
	if (flag == 1)
		pb(stack);
	else if (flag == 0)
		pa(stack);
	size--;
	return (size);
}

int	sort_brain(t_stack *stack)
{
	if (!stack_sorted(stack->a, stack->last_a))
	{
		if (stack->last_a == 2)
			sa(stack);
		else if (stack->last_a == 3)
			smol_sort(stack);
		else if (stack->last_a == 5)
			sort_five(stack);
		else if (stack->last_a <= 10)
			sort_ten(stack);
		else
			chunky_sort(stack, stack->last_a, 0);
	}
	return (0);
}
