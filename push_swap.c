/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:01:24 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/13 18:45:38 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = NULL;
	if (ac == 1)
		return (1);
	else if (ac < 2)
		return (0);
	stack = init_stack(ac, av);
	if (!stack)
		return (1);
	sort_brain(stack);
	ft_exit(stack);
	return (0);
}
