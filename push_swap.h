#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft/inc/libft.h"
# include <unistd.h>


typedef struct	s_stack
{
	int	*a;
	int	*b;
	int	*last_a;
	int	*last_b;
}	t_stack;

typedef	struct
{
	int	*parsed_data;
	bool	valid;
}	checkData;

bool	syntax_err(char *str);
bool	dup_err(int *data, int size);
void	ft_error(t_stack *stack);
void	fill_stack(int ac, char **av, int i, t_stack *stack);
checkData	input_check(char *str);
void	parse_data(int ac, char **av);
void	ft_exit(t_stack *stack);

#endif
