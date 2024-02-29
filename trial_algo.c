#include "push_swap.h"

typedef struct s_cost;
{
	int	index;
	bool	above_median;
	long	push_cost;
}	t_cost;

void	cost_analysis(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (i++ < len_a)
	{
		stack_a[i].push_cost = i;
		if (!(stack_a[i].above_median))
			stack_a[i].push_cost = len_a - i;
		if (stack_b->above_median)
			stack_a[i].push_cost += b->index;
		else
			stack_a[i].push_cost += len_b - stack_b->index;
	}
}

void set_cheapest(t_stack *stack, int size) {
    long cheapest_value = LONG_MAX;
    t_cost *cheapest_node = NULL;

    for (int i = 0; i < len; i++) {
        if (stack[i].push_cost < cheapest_value) {
            cheapest_value = stack[i].push_cost;
            cheapest_node = &stack[i];
        }
    }

    if (cheapest_node)
        cheapest_node->cheapest = true;
}
