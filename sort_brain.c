/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_brain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:14:30 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/05 23:38:23 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: stack_sorted
** -----------------------
** Checks if the given stack is sorted in ascending order.
**
** stack: Pointer to the stack array.
** size: Size of the stack.
**
** returns: true if the stack is sorted, false otherwise.
*/

bool	stack_sorted(int *stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (stack[i - 1] > stack[i])
			return (false);
		i++;
	}
	return (true);
}

/*
** Function: stack_sorted_desc
** ----------------------------
** Checks if the given stack is sorted in descending order.
**
** stack: Pointer to the stack array.
** size: Size of the stack.
**
** returns: true if the stack is sorted in descending order, false otherwise.
*/

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

/*
** Function: push_pop
** -------------------
** Pushes or pops an element from a stack, depending on the flag value.
**
** stack: Pointer to the stack structure.
** size: Current size of the stack.
** flag: Flag indicating the operation (1 for push, 0 for pop).
**
** returns: Updated size of the stack after the operation.
*/

int	push_pop(t_stack *stack, int size, int flag)
{
	if (flag == 1)
		pb(stack);
	else if (flag == 0)
		pa(stack);
	size--;
	return (size);
}

/*
** Function: sort_brain
** ---------------------
** Sorts the stack using appropriate sorting functions based on its size.
**
** stack: Pointer to the stack structure.
**
** returns: Always returns 0.
*/

int	sort_brain(t_stack *stack)
{
	if (!stack_sorted(stack->a, stack->last_a))
	{
		if (stack->last_a == 2)
			sa(stack);
		else if (stack->last_a == 3)
			smol_sort(stack);
		else if (stack->last_a <= 10)
			sort_ten(stack);
		else
			chunky_sort(stack, stack->last_a, 0);
	}
	return (0);
}
