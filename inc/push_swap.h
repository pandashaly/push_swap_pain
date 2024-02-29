/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:57:04 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/29 15:23:07 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include <unistd.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		last_a;
	int		last_b;
}		t_stack;

/*typedef struct s_checkData
{
	int		*parsed_data;
	bool	valid;
}			t_checkData;
*/

//bool		syntax_err(int *data);
void		dup_err(int *data, int size);
bool		stack_sorted(int *stack, int size);
void		ft_error(char *type);
void		fill_stack(int len, char **str, t_stack *stack, int i);
//checkData	input_check(t_stack *stack);
t_stack		*init_stack(int ac, char **av);
void		ft_exit(t_stack *stack);
//int			stack_len(int *stack, int size);
int			ft_superatoi(char *str);

int			sort_brain(t_stack *stack);
void		smol_sort(t_stack *stack);
int			smol_sort_b(t_stack *stack, int size);
void		tmp_sort(int *tmp_s, int size);
bool		stack_sorted_desc(int *stack, int size);
int			push_pop(t_stack *stack, int size, int flag);

/*	SORT	*/
int			chunky_sort(t_stack *stack, int size, int rotate_count);
int			quicksort_b(t_stack *stack, int size, int rotate_count);
int			partition(int *pivot, int *stack, int size);
void		qs_3ab(t_stack *stack, int size);


/*	COMMANDS	*/
int			sa(t_stack *stack);
int			sb(t_stack *stack);
int			ss(t_stack *stack);

int			ra(t_stack *stack);
int			rb(t_stack *stack);
int			rr(t_stack *stack);

int			rra(t_stack *stack);
int			rrb(t_stack *stack);
int			rrr(t_stack *stack);

int			pa(t_stack *stack);
int			pb(t_stack *stack);

#endif
