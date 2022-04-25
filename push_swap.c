/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:15:53 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/08 19:39:55 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*next;

	if (argc < 2)
		exit(0);
	a = create_stack(&(argv[1]), argc - 2);
	b = NULL;
	if (!(a->next->next))
		a = sort_two(a);
	else
		a = sort(a, b);
	while (a)
	{
		next = a->next;
		free(a);
		a = next;
	}
	exit(0);
}
