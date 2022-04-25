/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:22:38 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/08 19:08:39 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortik(t_stack **a, t_stack **b, t_stack *best)
{
	t_stack	*pos;
	int		a_top;
	int		a_bottom;
	int		b_top;
	int		b_bottom;

	best = find_best(*a, *b);
	pos = find_pos(*a, best->content);
	a_top = through_the_top(*a, pos->content);
	a_bottom = through_the_bottom(*a, pos->content);
	b_top = through_the_top(*b, best->content);
	b_bottom = through_the_bottom(*b, best->content);
	if (steps(*a, *b, best->content) == max(a_top, b_top))
		top(a, b, a_top, b_top);
	else if (steps(*a, *b, best->content) == max(a_bottom, b_bottom))
		bottom(a, b, a_bottom, b_bottom);
	else if (steps(*a, *b, best->content) == a_top + b_bottom)
		tuda_suda(a, b, a_top, b_bottom);
	else if (steps(*a, *b, best->content) == a_bottom + b_top)
		suda_tuda(a, b, a_bottom, b_top);
}

t_stack	*find_pos(t_stack *stk, int num)
{
	t_stack	*hstk;

	hstk = find_min(stk);
	while (hstk && hstk->content < num)
		hstk = hstk->next;
	if (!hstk)
	{
		hstk = stk;
		while (hstk != find_min(stk) && hstk->content < num)
			hstk = hstk->next;
	}
	return (hstk);
}

t_stack	*find_min(t_stack *a)
{
	t_stack	*stk;

	stk = a;
	while (a)
	{
		if (a->content < stk->content)
			stk = a;
		a = a->next;
	}
	return (stk);
}

int	through_the_top(t_stack *stk, int num)
{
	int	res;

	res = 0;
	while (stk && stk->content != num)
	{
		res++;
		stk = stk->next;
	}
	return (res);
}

int	through_the_bottom(t_stack *stk, int num)
{
	int	res;

	res = 0;
	while (stk && stk->content != num)
		stk = stk->next;
	while (stk)
	{
		res++;
		stk = stk->next;
	}
	return (res);
}
