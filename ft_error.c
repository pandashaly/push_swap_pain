/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:51:05 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/11 21:01:53 by ssottori         ###   ########.fr       */
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

void	ft_error(char *type, t_stack *stack, char **matrix)
{
	ft_printf("Error! %s", type);
	free_matrix(matrix);
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
	free(stack->a);
	free(stack->b);
	if (stack)
		free(stack);
	return ;
}
