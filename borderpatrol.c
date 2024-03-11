/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borderpatrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:46:32 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/11 20:38:01 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Border Patrol
//Check for +- (if yes continue if no stay same place)
//Check that next value is a digit (if yes go next if no instant deportation to rwanda scheme)
//Continue checking that there is ONLY digits until you get to end of this alleged immigrant (number)
//NEXT STAGE
//Convert this LEGAL immigrant to a LONG and check that the immigrant is not to fat or thin (INTMAX or INTMIN)
//Let them through border based of this and check for duplicates 
//Bang bang

#include "push_swap.h"

void	size_matters(long num, int sign, char **str2, t_stack *stack)
{
	if ((sign == -1 && num < INT_MIN) || (sign == 1 && num > INT_MAX))
	{
		free_matrix(str2);
		ft_error("Out of Range!", stack);
	}
}

int	ft_superatoi(char *str, char **str2, t_stack *stack)
{
	long			r;
	int			s;
	int			i;

	r = 0;
	s = 1;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = r * 10 + str[i++] - '0';
		size_matters(r, s, str2, stack);
	}
	if (str[i] && !ft_isdigit(str[i]))
		{
			//free_matrix(str2);
			ft_error("Non numeric character found!", stack);
		}
	return (r * s);
}
