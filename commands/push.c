/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:59:33 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/15 21:00:18 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *stack)
{
	int	len;

	len = stack->last_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->last_a++;
	stack->a[0] = stack->b[0];
	len = 1;
	while (len < stack->last_b)
	{
		stack->b[len - 1] = stack->b[len];
		len++;
	}
	stack->last_b--;
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *stack)
{
	int	len;

	len = stack->last_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->last_b++;
	stack->b[0] = stack->a[0];
	len = 1;
	while (len < stack->last_a)
	{
		stack->a[len - 1] = stack->a[len];
		len++;
	}
	stack->last_a--;
	write(1, "pb\n", 3);
	return (1);
}
