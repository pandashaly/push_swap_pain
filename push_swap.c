/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:01:24 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/01 16:46:44 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	print_stack(t_stack *stack)
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
	ft_printf("Stack len is %d\n", stack->last_a);
}*/

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
		ft_error("Empty Stack");
	sort_brain(stack);
	ft_exit(stack);
	return (0);
}
