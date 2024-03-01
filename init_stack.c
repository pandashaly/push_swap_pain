/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:46:40 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/01 17:37:13 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_matrix(char **matrix);

t_stack	*init_stack(int ac, char **av)
{
	t_stack		*stack;
	char		**str;
	int			len;

	len = 0;
	stack = NULL;
	stack = malloc(sizeof(t_stack));
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if (!str)
			ft_error("Split failed");
		while (str[len])
			len++;
		fill_stack(len, str, stack, 0);
		free_matrix(str);
	}
	else if (ac >= 3)
		fill_stack(ac, av, stack, 1);
	else
		exit(EXIT_FAILURE);
	return (stack);
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
