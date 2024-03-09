/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:46:40 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/09 01:53:11 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: init_stack
** ---------------------
** Initializes the stack structure based on the command line args.
** If there's only one arg, it splits it into tokens and fills the stack.
** Otherwise, it directly fills the stack.
**
** ac: The number of command line arguments.
** av: Array of command line arguments.
**
** returns: Pointer to the initialized stack structure.
*/

t_stack	*init_stack(int ac, char **av)
{
	t_stack		*stack;
	char		**str;
	int			len;

	len = 0;
	str = NULL;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		while (str[len])
			len++;
		stack = malloc(sizeof(t_stack));
		fill_stack(len, str, stack, 0);
		//free_matrix(str);
	}
	else if (ac >= 3)
	{
		stack = malloc(sizeof(t_stack));
		fill_stack(ac, av, stack, 1);
	}
	else
		exit(EXIT_FAILURE);
	return (stack);
}

/*
** Function: fill_stack
** ---------------------
** Fills the stack with integers from the given array of strings.
** Converts the string tokens to integers with atoi and stores them in the 
** stack's 'a' array.
** Then calls dup_err to check for duplicate numebrs.
**
** ac: The number of args or strings in the array.
** str: Array of strings containing integer representations.
** stack: Pointer to the stack structure.
** i: Index to start filling the stack from.
**
** returns: None.
*/

void	fill_stack(int ac, char **str, t_stack *stack, int i)
{
	int	len;

	len = 0;
	stack->a = (int *)malloc(sizeof(int) * (ac));
	stack->b = (int *)malloc(sizeof(int) * (ac));
	while (i < ac)
		stack->a[len++] = ft_superatoi(str[i++], str, stack);
	dup_err(stack->a, len, str, stack);
	stack->last_a = len;
	stack->last_b = 0;
}

/*
** Function: dup_err
** ------------------
** Checks for duplicate elements in the integer array.
** If duplicates are found, it displays an error message and exits the program.
**
** data: Array of integers.
** size: Size of the array.
**
** returns: None.
*/

void	dup_err(int *data, int size, char **str, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (data[i] == data[j])
			{
				free_matrix(str);
				ft_error("Duplicate found", stack);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

/*
** Function: free_matrix
** ----------------------
** Frees memory allocated for a 2D array of strings.
**
** matrix: Array of strings.
**
** returns: None.
*/

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}
