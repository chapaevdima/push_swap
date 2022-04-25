/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:32:35 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/10 17:30:03 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"
# include "get_next_line_bonus.h"

int		ft_strcmp(const char *str1, const char *str2);
void	help(t_stack **a, t_stack **b, char *line);
void	do_something(t_stack **a, t_stack **b, char *line);
t_stack	*create_stack_checker(char **strs, int n);
#endif