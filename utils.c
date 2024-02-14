/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:34 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/14 19:39:25 by ssottori         ###   ########.fr       */
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

int	sort_brain(t_stack *stack)
{
	if (!stack_sorted(stack->a, stack->last_a))
	{
		if (stack->last_a == 2)
			sa(stack);
		else if (stack->last_a == 3)
			smol_sort(stack);
		//else
			//chunky_sort(stack, stack->last_a, 0);
	}
	return (0);
}

void	smol_sort(t_stack *stack)
{
	if ((stack->a[0] < stack->a[1]) && (stack->a[0] < stack->a[2])
		&& (stack->a[1] > stack->a[2]))
	{
		sa(stack);
		ra(stack);
	}
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] > stack->a[2]))
	{
		sa(stack);
		rra(stack);
	}
	else if ((stack->a[0] < stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] > stack->a[2]))
		rra(stack);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] < stack->a[2]))
		ra(stack);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] < stack->a[2])
		&& (stack->a[1] < stack->a[2]))
		sa(stack);
}
