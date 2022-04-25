/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:40:57 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/07 14:15:14 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_best(t_stack *a, t_stack *b)
{
	t_stack	*res;
	t_stack	*stk;

	stk = b;
	res = b;
	while (stk)
	{
		if (steps(a, b, stk->content) < steps(a, b, res->content))
			res = stk;
		stk = stk->next;
	}
	return (res);
}

int	steps(t_stack *a, t_stack *b, int content)
{
	t_stack	*pos;
	int		a_top;
	int		a_bottom;
	int		b_top;
	int		b_bottom;

	pos = find_pos(a, content);
	a_top = through_the_top(a, pos->content);
	a_bottom = through_the_bottom(a, pos->content);
	b_top = through_the_top(b, content);
	b_bottom = through_the_bottom(b, content);
	return (min(min(max(b_bottom, a_bottom), max(a_top, b_top)),
			min(a_bottom + b_top, a_top + b_bottom)));
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
