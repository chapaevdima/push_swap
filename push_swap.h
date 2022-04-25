/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:17:58 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/10 15:54:31 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int		ft_atoi(const char *str);
t_stack	*create_stack(char **strs, int n);
t_stack	*swap(t_stack *stk);
t_stack	*get_last(t_stack *stk);
t_stack	*rotate(t_stack *stk);
t_stack	*get_prelast(t_stack *stk);
t_stack	*reverse_rotate(t_stack *stk);
void	push(t_stack **a, t_stack **b);
void	check_double(t_stack *stk);
int		is_sorted(t_stack *a);
t_stack	*sort(t_stack *a, t_stack *b);
void	push_print(t_stack **a, t_stack **b, char c);
void	push_print(t_stack **a, t_stack **b, char c);
t_stack	*swap_print(t_stack *stk, char c);
void	double_swap(t_stack **a, t_stack **b);
t_stack	*rotate_print(t_stack *stk, char c);
void	double_rotate(t_stack **a, t_stack **b);
t_stack	*reverse_rotate_print(t_stack *stk, char c);
void	double_reverse_rotate(t_stack **a, t_stack **b);
t_stack	*sort_two(t_stack *stk);
t_stack	*sort_three(t_stack *stk);
int		through_the_bottom(t_stack *stk, int num);
int		through_the_top(t_stack *stk, int num);
t_stack	*find_min(t_stack *a);
t_stack	*find_pos(t_stack *stk, int num);
t_stack	*find_best(t_stack *a, t_stack *b);
int		steps(t_stack *a, t_stack *b, int content);
int		min(int a, int b);
int		max(int a, int b);
void	top(t_stack **a, t_stack **b, int a_top, int b_top);
void	bottom(t_stack **a, t_stack **b, int a_bottom, int b_bottom);
void	tuda_suda(t_stack **a, t_stack **b, int top, int bottom);
void	suda_tuda(t_stack **a, t_stack **b, int bottom, int top);
void	sortik(t_stack **a, t_stack **b, t_stack *best);
void	error(void);
void	delete_stack(t_stack *stk);

#endif
