/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:30:59 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/10 17:28:57 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*create_stack_checker(char **strs, int n)
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
	return (res);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\n')
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	help(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "rra\n"))
		*a = reverse_rotate(*a);
	else if (!ft_strcmp(line, "rrb\n"))
		*b = reverse_rotate(*b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		*a = reverse_rotate(*a);
		*b = reverse_rotate(*b);
	}
	else
		error();
}

void	do_something(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		*a = swap(*a);
	else if (!ft_strcmp(line, "sb\n"))
		*b = swap(*b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		*a = swap(*a);
		*b = swap(*b);
	}
	else if (!ft_strcmp(line, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(line, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		*a = rotate(*a);
	else if (!ft_strcmp(line, "rb\n"))
		*b = rotate(*b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		*a = rotate(*a);
		*b = rotate(*b);
	}
	else
		help(a, b, line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		exit(0);
	a = create_stack_checker(&(argv[1]), argc - 2);
	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		do_something(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	delete_stack(a);
	delete_stack(b);
}
