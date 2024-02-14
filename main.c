/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:54:57 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/11 21:01:18 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_superatoi(char *str)
{
	long int		r;
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

bool	dup_err(int *data, int size)
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
				return false;
			j++;
		}
		i++;
		j = i + 1;
	}
	return true;
}

bool	syntax_err(char *str)
{
	if (!(ft_issign(*str) || ft_isdigit(*str)))
		return false;
	if ((ft_issign(*str)) && !(ft_isdigit(str[1])))
		return false;
	while (*++str)
	{
		if (!(ft_isdigit(*str)))
			return false;
	}
	return true;
}

void	ft_error(char *type)
{
	//ft_exit(stack);
	ft_printf("Error! %s", type);
	exit (EXIT_FAILURE);
}

void	fill_stack(int ac, char **str, t_stack *stack, int i)
{
	int	len;

	len = 0;
	stack->a = malloc(sizeof(int) * (ac - 1));
	stack->b = malloc(sizeof(int) * (ac - 1));
	while (i < ac)
		stack->a[len++] = ft_superatoi(str[i++]);
	stack->last_a = len;
	stack->last_b = 0;
}

checkData	input_check(char *str)
{
	int		size;
	int		*data;
	checkData	result;
	int		num;

	size = 0;
	result.valid = true;
	while (*str)
	{
		if (!syntax_err(str))
		{
			result.valid = false;
			return (result);
		}
		if (ft_isdigit(*str))
		{
			num = ft_atol(str);
			data = &num;
		}
		if (!data)
		{
			result.valid = false;
			break ;
		}
		while (data[size])
			size++;
		if (!dup_err(data, size))
		{
			result.valid = false;
			break ;
		}
		str++;
	}
	result.parsed_data = data;
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
	checkData checked;

	str = NULL;
	len = 0;
	stack = NULL;
	checked.parsed_data = NULL;
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
	if (stack->last_a == 1)
		ft_exit(stack);
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
	//stack = malloc(sizeof(t_stack));
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
	print_stack(stack);
	ft_exit(stack);
	return (0);
}
