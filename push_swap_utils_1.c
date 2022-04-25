/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:08:08 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/10 15:33:16 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*reverse_rotate(t_stack *stk)
{
	t_stack	*prelast;
	t_stack	*hstk;

	if (!stk || !stk->next)
		return (stk);
	prelast = get_prelast(stk);
	hstk = prelast->next;
	prelast->next = NULL;
	hstk->next = stk;
	return (hstk);
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*stk;

	if (!(*a))
		return ;
	stk = (*a)->next;
	(*a)->next = (*b);
	(*b) = stk;
	stk = *a;
	*a = *b;
	*b = stk;
}

t_stack	*rotate(t_stack *stk)
{
	t_stack	*h1stk;
	t_stack	*h2stk;

	if (!stk || !stk->next)
		return (stk);
	h1stk = stk;
	stk = stk->next;
	h2stk = get_last(stk);
	h2stk->next = h1stk;
	h1stk->next = NULL;
	return (stk);
}

t_stack	*swap(t_stack *stk)
{
	int	k;

	if (!stk)
		return (stk);
	k = stk->content;
	stk->content = stk->next->content;
	stk->next->content = k;
	return (stk);
}

t_stack	*create_stack(char **strs, int n)
{
	t_stack	*new;
	t_stack	*res;
	int		i;

	i = 0;
	res = NULL;
	while (n >= i)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			exit(0);
		new->content = ft_atoi(strs[i]);
		new->next = NULL;
		if (!res)
			res = new;
		else
			get_last(res)->next = new;
		i++;
	}
	check_double(res);
	if (is_sorted(res))
		exit(0);
	return (res);
}
