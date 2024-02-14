/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:57:04 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/11 20:59:10 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include <unistd.h>

typedef struct	s_stack
{
	int	*a;
	int	*b;
	int	last_a;
	int	last_b;
}	t_stack;

typedef	struct
{
	int	*parsed_data;
	bool	valid;
}	checkData;

bool	syntax_err(int *data);
void	dup_err(int *data, int size);
bool	stack_sorted(int *stack, int size);
void	ft_error(char *type);
void	fill_stack(int len, char **str, t_stack *stack, int i);
checkData	input_check(t_stack *stack);
t_stack	*init_stack(int ac, char **av);
void	ft_exit(t_stack *stack);
int	ft_superatoi(char *str);

#endif
