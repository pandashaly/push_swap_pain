/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:40:08 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/19 16:06:17 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_needs(t_stack *stack)
{
	if (stack->last_a == 5)
	{
		if (stack->a[0] == 5 && stack->a[1] == 4 && stack->a[2] == 2
			&& stack->a[3] == 3 && stack->a[4] == 1)
		{
			sa(stack);
			ra(stack);
			sa(stack);
		}
		else if (stack->a[0] == 5 && stack->a[1] == 4 && stack->a[2] == 2
			&& stack->a[3] == 1 && stack->a[4] == 3)
		{
			ra(stack);
			sa(stack);
		}
		else if (stack->a[0] == 3 && stack->a[1] == 5 && stack->a[2] == 4
			&& stack->a[3] == 2 && stack->a[4] == 1)
		{
			rra(stack);
			sa(stack);
		}
	}
}
