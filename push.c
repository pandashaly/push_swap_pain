/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:10:07 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/14 18:08:00 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	int	tmp;

	if (!stack->a[0] || !stack->a[1])
		return (0);
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	write (1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *stack)
{
	int	tmp;

	if (stack->last_b == 0 || stack->last_b == 1)
		return (0);
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	write (1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *stack)
{
	int	tmp;

	if (!stack->a[0] || !stack->a[1] || !stack->b[0] || !stack->b[1])
		return (0);
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	write (1, "ss\n", 3);
	return (1);
}
