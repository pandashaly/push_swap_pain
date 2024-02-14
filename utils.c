#include "push_swap.h"

bool	stack_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i - 1] > stack[i])
			return false;
		i++;
	}
	return true;
}

