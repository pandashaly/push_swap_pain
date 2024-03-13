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

/*
** Function: smol_sort
** --------------------
** Sorts a stack of size 3 using a predefined set of moves.
** stack: Pointer to the stack structure.
**
** returns: None.
*/

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

/*
** Function: smol_sort_b
** -----------------------
** Sorts a stack of size 1, 2, or 3 using predefined moves.
** Moves elements from stack B to stack A as needed to sort.
**
** stack: Pointer to the stack structure.
** size: Size of the stack B (stack->last_b)
**
** returns: 0.
*/

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

/*
** Function: tmp_sort
** ------------------
** Sorts an array of integers in ascending order using bubble sort.
**
** tmp_s: Pointer to the array of integers.
** size: Size of the array.
**
** returns: None.
*/

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
