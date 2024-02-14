/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:54:57 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/14 19:47:54 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_superatoi(char *str)
{
	long int	r;
	int			s;
	int			i;

	r = 0;
	s = 1;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("Non numeric character found!");
		r = r * 10 + str[i++] - '0';
	}
	if (r > 2147483647 || r < -2147483647)
		ft_error("Out of Range!");
	return (r * s);
}

void	dup_err(int *data, int size)
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
				ft_error("Duplicate found");
			j++;
		}
		i++;
		j = i + 1;
	}
}

bool	syntax_err(int *data)
{
	if (!(ft_issign(*data) || ft_isdigit(*data)))
		return (false);
	if ((ft_issign(*data)) && !(ft_isdigit(data[1])))
		return (false);
	while (*++data)
	{
		if (!(ft_isdigit(*data)))
			return (false);
	}
	return (true);
}

void	ft_error(char *type)
{
	ft_printf("Error! %s", type);
	exit (EXIT_FAILURE);
}

void	fill_stack(int ac, char **str, t_stack *stack, int i)
{
	int	len;

	len = 0;
	stack->a = (int *)malloc(sizeof(int) * (ac - 1));
	stack->b = (int *)malloc(sizeof(int) * (ac - 1));
	while (i < ac)
		stack->a[len++] = ft_superatoi(str[i++]);
	dup_err(stack->a, len);
	stack->last_a = len;
	stack->last_b = 0;
}

checkData	input_check(t_stack *stack)
{
	int			size;
	int			*data;
	checkData	result;

	size = 0;
	result.valid = true;
	data = stack->a;
	while (size < stack->last_a)
	{
		if (!syntax_err(data))
		{
			result.valid = false;
			return (result);
		}
		if (!data)
		{
			result.valid = false;
			ft_error("Stack is empty");
			break ;
		}
		size++;
	}
	return (result);
}

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**str;
	int	len;

	str = NULL;
	len = 0;
	stack = NULL;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if (!str)
			ft_error("Split failed");
		while (str[len])
			len++;
		stack = malloc(sizeof(t_stack));
		fill_stack(len, str, stack, 0);
		free_matrix(str);
	}
	else if (ac >= 3)
	{
		stack = malloc(sizeof(t_stack));
		fill_stack(ac, av, stack, 1);
	}
	else
		ft_error("Wrong number of args.");
	return (stack);
}

void	ft_exit(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	if (stack)
		free(stack);
	return ;
}

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
	{
		ft_error("Not enough args");
		return (1);
	}
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
