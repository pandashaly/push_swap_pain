/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:01:24 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/15 21:45:20 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack == NULL || stack->a == NULL || stack->last_a == 0)
		ft_error("Empty Stack");
	ft_printf("Stack: \n");
	while (i < stack->last_a)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac < 2)
		return (0);
	stack = init_stack(ac, av);
	if (!stack)
		ft_error("Initializing Stack");
	sort_brain(stack);
	if (stack_sorted(stack->a, stack->last_a))
		ft_printf("Stack sorted\n");
	else if (!stack_sorted(stack->a, stack->last_a))
		ft_printf("Stack unsorted\n");
	print_stack(stack);
	ft_exit(stack);
	return (0);
}
