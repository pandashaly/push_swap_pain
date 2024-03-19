/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:57:04 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/13 18:37:50 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include <unistd.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		last_a;
	int		last_b;
	char	**matrix;
	bool	splitted;
}	t_stack;

void	dup_err(int *data, int size, t_stack *stack);
bool	stack_sorted(int *stack, int size);
void	ft_error(t_stack *stack);
void	fill_stack(int len, t_stack *stack, int i);
t_stack	*init_stack(int ac, char **av);
void	ft_exit(t_stack *stack);
int		ft_superatoi(char *str, t_stack *stack);
void	free_matrix(t_stack *stack);
void	splitting(t_stack *stack, int len);
size_t	strarr_len(char **arr);
void	special_needs(t_stack *stack);

int		sort_brain(t_stack *stack);
void	smol_sort(t_stack *stack);
int		smol_sort_b(t_stack *stack, int size);
void	tmp_sort(int *tmp_s, int size);
bool	stack_sorted_desc(int *stack, int size);
int		push_pop(t_stack *stack, int size, int flag);

/*	SORT	*/
int		chunky_sort(t_stack *stack, int size, int rotate_count);
int		quicksort_b(t_stack *stack, int size, int rotate_count);
int		partition(int *pivot, int *stack, int size);
void	qs_3ab(t_stack *stack, int size);

/*	COMMANDS	*/
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack);

int		ra(t_stack *stack);
int		rb(t_stack *stack);
int		rr(t_stack *stack);

int		rra(t_stack *stack);
int		rrb(t_stack *stack);
int		rrr(t_stack *stack);

int		pa(t_stack *stack);
int		pb(t_stack *stack);

int		find_smol(t_stack *stack);
int		find_beeg(t_stack *stack);
void	sort_five(t_stack *stack);
void	sort_ten(t_stack *stack);

#endif
