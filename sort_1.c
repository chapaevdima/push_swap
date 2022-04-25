/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:48:23 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/08 19:10:38 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort(t_stack *a, t_stack *b)
{
	while (!is_sorted(a) && a->next->next->next)
		push_print(&a, &b, 'b');
	a = sort_three(a);
	while (b)
		sortik(&a, &b, NULL);
	if (!is_sorted(a))
	{
		if (through_the_top(a, find_min(a)->content)
			<= through_the_bottom(a, find_min(a)->content))
			while (a != find_min(a))
				a = rotate_print(a, 'a');
		else
			while (a != find_min(a))
				a = reverse_rotate_print(a, 'a');
	}
	return (a);
}

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*sort_two(t_stack *stk)
{
	stk = swap_print(stk, 'a');
	return (stk);
}

t_stack	*sort_three(t_stack *stk)
{
	is_sorted(stk);
	if (stk->content > stk->next->content
		&& stk->content > stk->next->next->content)
		stk = rotate_print(stk, 'a');
	if (stk->next->content > stk->content
		&& stk->next->content > stk->next->next->content)
		stk = reverse_rotate_print(stk, 'a');
	if (is_sorted(stk))
		return (stk);
	stk = swap_print(stk, 'a');
	return (stk);
}
