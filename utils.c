/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:43:33 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/19 15:41:41 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smol(t_stack *stack)
{
	int	smol;
	int	i;

	i = 0;
	smol = stack->a[stack->last_a - 1];
	while (i < stack->last_a)
	{
		if (stack->a[i] < smol)
			smol = stack->a[i];
		i++;
	}
	return (smol);
}

void	sort_five(t_stack *stack)
{
	if (stack->last_a == 5)
	{
		special_needs(stack);
		if (stack_sorted_desc(stack->a, stack->last_a)
			&& !stack_sorted(stack->a, stack->last_a))
			rra(stack);
		while (!stack_sorted(stack->a, stack->last_a))
		{
			if (stack->a[0] == find_smol(stack))
				pb(stack);
			else if (stack->last_a == 3)
				smol_sort(stack);
			else
				ra(stack);
		}
		while (stack->last_b > 0)
			pa(stack);
	}
}

void	sort_ten(t_stack *stack)
{
	if (stack->last_a <= 10)
	{
		while (!stack_sorted(stack->a, stack->last_a))
		{
			if (stack->a[0] == find_smol(stack)
				|| (stack->last_b >= 1 && stack->a[0] == find_beeg(stack)))
				pb(stack);
			else
				ra(stack);
		}
		while (stack->last_b)
			pa(stack);
	}
}

int	find_beeg(t_stack *stack)
{
	int	beeg;
	int	i;

	i = stack->last_b;
	beeg = stack->b[stack->last_b - 1];
	while (i)
	{
		--i;
		if (stack->b[i] > beeg)
			beeg = stack->b[i];
	}
	return (beeg);
}
