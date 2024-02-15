/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:25:07 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/14 19:39:45 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->last_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->b[0];
	while (++i < stack->last_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->last_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	i = -1;
	tmp = stack->b[0];
	while (++i < stack->last_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	write(1, "rr\n", 3);
	return (1);
}
