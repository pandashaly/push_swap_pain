/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:51:05 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/15 20:52:59 by ssottori         ###   ########.fr       */
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

void	ft_error(char *type)
{
	ft_printf("Error! %s", type);
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
