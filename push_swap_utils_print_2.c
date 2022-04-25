/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_print_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:46:59 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/10 16:05:14 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*reverse_rotate_print(t_stack *stk, char c)
{
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (reverse_rotate(stk));
}

void	double_reverse_rotate(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	*a = reverse_rotate(*a);
	*b = reverse_rotate(*b);
}

void	delete_stack(t_stack *stk)
{
	t_stack	*next;

	while (stk)
	{
		next = stk->next;
		free(stk);
		stk = next;
	}
}
