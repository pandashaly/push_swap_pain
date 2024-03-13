/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:26:21 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/12 22:20:57 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->last_a - 1];
	len = stack->last_a - 1;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->a[0] = tmp;
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->b[stack->last_b - 1];
	len = stack->last_b;
	while (len-- > 0)
		stack->b[len] = stack->b[len - 1];
	stack->b[0] = tmp;
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->last_a - 1];
	len = stack->last_a;
	while (len-- > 0)
		stack->a[len] = stack->a[len - 1];
	stack->a[0] = tmp;
	tmp = stack->b[stack->last_b - 1];
	len = stack->last_b;
	while (len-- > 0)
		stack->b[len] = stack->b[len - 1];
	stack->b[0] = tmp;
	write(1, "rrr\n", 4);
	return (1);
}
