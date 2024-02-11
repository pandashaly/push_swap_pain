#include "push_swap.h"

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

void	ft_error(t_stack *stack)
{
	ft_exit(stack);
	write (1, "Error!\n", 7);
	exit (EXIT_FAILURE);
}

void	fill_stack(int len, int *data, t_stack *stack)
{
	int	i;

	i = 0;
	stack->a = malloc(sizeof(int) * len); //?
	stack->b = malloc(sizeof(int) * len);
	while (i < len)
	{
		stack->a[i] = data[i]; //i?
		i++;
	}
	stack->last_a = len;
	stack->last_b = 0;
}

checkData	input_check(char *str)
{
	int		size;
	int		data;
	checkData	result;

	size = 0;
	result.valid = true;
	while (*str)
	{
		if (!syntax_err(str))
		{
			result.valid = false;
			break ;
		}
		if (ft_isdigit(*str))
			data = ft_atoi(str);
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

t_stack	init_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**str;
	int	len;
	checkData checked;

	str = NULL;
	len = 0;
	stack = NULL;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if (!str)
			ft_error(stack); // FIX THIS ---> change 
		checked = input_check(*str);
		if (!checked.valid)
			ft_error(stack);
		while (parsed_data.checked[len])
			len++;
		stack = malloc(len * sizeof(t_stack)); //?
		fill_stack(len, parsed_data.checked, 0, stack); //?
	}
	else if (ac >= 3)
	{
		stack = malloc(ac - 1) * sizeof(t_stack);
		fill_stack(ac, av, 1, stack);
	}
	else
		ft_error(stack);
	free(str);
	return (*stack);
}

void	ft_exit(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	if (stack)
		free(stack);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = NULL;
	if (ac == 1 || (ac == 2 && av[1][0]))
		return (0); // or 1?
	*stack = init_stack(ac, av);
	ft_printf("Stack a: %d\n", print_stack(stack->a));
	return (0);
}
