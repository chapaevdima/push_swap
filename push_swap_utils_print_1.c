/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_print_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:11:05 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/08 18:56:15 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_print(t_stack **a, t_stack **b, char c)
{
	push(a, b);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

t_stack	*swap_print(t_stack *stk, char c)
{
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (swap(stk));
}

void	double_swap(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	*a = swap(*a);
	*b = swap(*b);
}

t_stack	*rotate_print(t_stack *stk, char c)
{
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (rotate(stk));
}

void	double_rotate(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	*a = rotate(*a);
	*b = rotate(*b);
}
