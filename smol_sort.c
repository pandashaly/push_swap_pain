/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:15:03 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/29 15:32:38 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	smol_sort_b(t_stack *stack, int size)
{
	if (size == 1)
		pa(stack);
	else if (size == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack);
		while (size--)
			pa(stack);
	}
	else if (size == 3)
	{
		while (size
			|| !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (size == 1 && stack->a[0] > stack->a[1])
				sa(stack);
			else if (size == 1
				|| (size >= 2 && stack->b[0] > stack->b[1])
				|| (size == 3 && stack->b[0] > stack->b[2]))
				size = push_pop(stack, size, 0);
			else
				sb(stack);
		}
	}
	return (0);
}

void	tmp_sort(int *tmp_s, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_s[i] > tmp_s[j])
			{
				tmp = tmp_s[i];
				tmp_s[i] = tmp_s[j];
				tmp_s[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
