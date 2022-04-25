/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:13:44 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/08 13:47:33 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top(t_stack **a, t_stack **b, int a_top, int b_top)
{
	while (a_top && b_top)
	{
		double_rotate(a, b);
		a_top--;
		b_top--;
	}
	while (a_top)
	{
		*a = rotate_print(*a, 'a');
		a_top--;
	}
	while (b_top)
	{
		*b = rotate_print(*b, 'b');
		b_top--;
	}
	push_print(b, a, 'a');
}

void	bottom(t_stack **a, t_stack **b, int a_bottom, int b_bottom)
{
	while (a_bottom && b_bottom)
	{
		double_reverse_rotate(a, b);
		a_bottom--;
		b_bottom--;
	}
	while (a_bottom)
	{
		*a = reverse_rotate_print(*a, 'a');
		a_bottom--;
	}
	while (b_bottom)
	{
		*b = reverse_rotate_print(*b, 'b');
		b_bottom--;
	}
	push_print(b, a, 'a');
}

void	tuda_suda(t_stack **a, t_stack **b, int top, int bottom)
{
	while (top--)
		*a = rotate_print(*a, 'a');
	while (bottom--)
		*b = reverse_rotate_print(*b, 'b');
	push_print(b, a, 'a');
}

void	suda_tuda(t_stack **a, t_stack **b, int bottom, int top)
{
	while (top--)
		*b = rotate_print(*b, 'b');
	while (bottom--)
		*a = reverse_rotate_print(*a, 'a');
	push_print(b, a, 'a');
}
