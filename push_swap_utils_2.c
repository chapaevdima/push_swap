/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:23:51 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/08 19:07:45 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write (1, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		neg;

	neg = 1;
	res = 0;
	i = 0;
	if (str[0] == '-')
	{
		i = 1;
		neg = -1;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		else
			error();
		if (res * neg > INT_MAX || res * neg < INT_MIN)
			error();
		i++;
	}
	return (res * neg);
}

t_stack	*get_last(t_stack *stk)
{
	if (stk == NULL)
		return (NULL);
	while (stk->next)
		stk = stk->next;
	return (stk);
}

t_stack	*get_prelast(t_stack *stk)
{
	if (stk == NULL || stk->next == NULL)
		return (NULL);
	while (stk->next->next)
		stk = stk->next;
	return (stk);
}

void	check_double(t_stack *stk)
{
	t_stack	*hstk;

	while (stk)
	{
		hstk = stk->next;
		while (hstk)
		{
			if (hstk->content == stk->content)
				error();
			hstk = hstk->next;
		}
		stk = stk->next;
	}
}
