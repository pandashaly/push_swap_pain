/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunky_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:54:34 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/05 23:44:20 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: chunky_sort (quicksort_a)
** -----------------------
** Sorts a stack of integers using the chunky sort algorithm.
** It takes in three parameters: a stack, which contains two arrays (a and b),
** the size of the array to be sorted (stack->last_a), and a rotate count (0).
** It first checks if the array is already sorted with "stack_sorted".
** If it is, it returns 1 indicating that no further sorting needs to be done.
** Next, it checks if there are only 3 or fewer elements in the array. 
** If true, it calls "qs_3ab" for sorting.
** If neither of these conditions is met, it proceeds with chunky sort algo.
** The function chooses a pivot element using the "partition" function.
** It then separates the elements into two stacks, A and B, based on 
their relation to the pivot.
** The function recursively calls itself to sort the two sub-arrays 
until all elements are sorted.
**
** stack: Pointer to the stack structure.
** size: Size of the array to be sorted.
** rotate_count: Counter for rotations performed.
**
** returns: 1 if the sorting is successful, 0 otherwise.
*/

static void	rra_round(t_stack *stack, int rotate_count, int numbers, int size)
{
	int	og_size;

	og_size = size;
	while (rotate_count--
		&& og_size != stack->last_a + stack->last_b
		&& numbers / 2 != stack->last_a)
		rra(stack);
}

int	chunky_sort(t_stack *stack, int size, int rotate_count)
{
	int	pivot;
	int	numbers;

	if (stack_sorted(stack->a, size) == 1)
		return (1);
	numbers = size;
	if (size <= 3)
	{
		qs_3ab(stack, size);
		return (1);
	}
	if (!rotate_count && !partition(&pivot, stack->a, size))
		return (0);
	while (size != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < pivot && (size--))
			pb(stack);
		else if (++rotate_count)
			ra(stack);
	}
	rra_round(stack, rotate_count, numbers, stack->last_a); 
	return (chunky_sort(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stack, numbers / 2, 0));
	return (1);
}

/*
** Function: quicksort_b
** ----------------------
** This function sorts the B stack in descending order using the quicksort algo.
** It first checks if the B stack is already sorted in descending order.
** If true, it moves all elements to stack A using the "pa" function.
** Next, it checks if there are only 3 or fewer elements in the B stack.
** If true, it calls "smol_sort_b" for sorting.
** If neither of these conditions is met, it proceeds with the quicksort algo.
** The function chooses a pivot element using the "partition" function.
** It then separates the elements into two sub-arrays, 
pushing elements to stack A or maintaining them in stack B 
based on their relation to the pivot.
** The function recursively calls itself to sort the two sub-arrays 
until all elements are sorted.
**
** stack: Pointer to the stack structure.
** size: Size of the array to be sorted.
** rotate_count: Counter for rotations performed.
**
** returns: 1 if the sorting is successful, 0 otherwise.
*/

int	quicksort_b(t_stack *stack, int size, int rotate_count)
{
	int	pivot;
	int	numbers;

	if (!rotate_count && stack_sorted_desc(stack->b, size) == 1)
		while (size--)
			pa(stack);
	if (size <= 3)
	{
		smol_sort_b(stack, size);
		return (1);
	}
	numbers = size;
	if (!partition(&pivot, stack->b, size))
		return (0);
	while (size != numbers / 2)
	{
		if (stack->b[0] >= pivot && size--)
			pa(stack);
		else if (++rotate_count)
			rb(stack);
	}
	while (numbers / 2 != stack->last_b && rotate_count--)
		rrb(stack);
	return (chunky_sort(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stack, numbers / 2, 0));
}

/*
** Function: partition
** ---------------------
** Here we partition an array into two sub-arrays based on pivot element.
** It first creates a temp array and copies the elements of the original array.
** It then sorts the temp array and selects the pivot as the mid element.
** The function frees the memory allocated for the temporary array
** and returns the pivot element.
**
** pivot: Pointer to store the pivot element.
** stack: Pointer to the original array.
** size: Size of the array.
**
** returns: 1 if the partitioning is successful, 0 otherwise.
*/

int	partition(int *pivot, int *stack, int size)
{
	int	i;
	int	j;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (i < size)
		tmp[j++] = stack[i++];
	tmp_sort(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}

/*
** Function: qs_3ab
** ------------------
** This function sorts an array of 3 integers in ascending order.
** If the array size is 3, it checks for all possible cases
** and sorts the array accordingly.
** The function performs necessary swap operations using the "sa" function.
**
** stack: Pointer to the stack structure.
** size: Size of the array to be sorted.
**
** returns: None.
*/

void	qs_3ab(t_stack *stack, int size)
{
	if (size == 3 && stack->last_a == 3)
		smol_sort(stack);
	else if (size == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
	else if (size == 3)
	{
		while (size != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if ((size == 3) && (stack->a[0] > stack->a[1] && stack->a[2]))
				sa(stack);
			else if (size == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				size = push_pop(stack, size, 1);
			else if (stack->a[0] > stack->a[1])
				sa(stack);
			else if (size++)
				pa(stack);
		}
	}
}
