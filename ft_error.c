/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:51:05 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/13 18:44:40 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_error
** -------------------
** Displays an error message & exits the program with failure status.
** type: Pointer to a string containing the type of error.
**
** returns: None.
*/

void	ft_error(char *type, t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	ft_printf("%s\n", type);
	if (stack->splitted)
		free_matrix(stack);
	ft_exit(stack);
	exit (EXIT_FAILURE);
}

/*
** Function: ft_exit
** ------------------
** Frees the memory allocated for the stack structure and its arrays.
** stack: Pointer to the stack structure.
**
** returns: None.
*/

void	ft_exit(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
	return ;
}

void	splitting(t_stack *stack, int len)
{
	stack->splitted = true;
	stack->matrix = ft_split(stack->matrix[1], ' ');
	if (!stack->matrix)
		ft_error("Split failed", stack);
	if (!strarr_len(stack->matrix))
		ft_error("Split empty", stack);
	while (stack->matrix[len])
		len++;
	fill_stack(len, stack, 0);
	free_matrix(stack);
}

size_t	strarr_len(char **arr)
{
	size_t	i;

	i = 0;
	while (*arr++)
		i++;
	return (i);
}
