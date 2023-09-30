/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:09:22 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/18 18:19:02 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*stack;
	int		size;

	if (argc < 2)
		return (0);
	stack = parse(&argv[1], argc - 1, &size);
	make_stacks(&a, &b, stack, size);
	if (!size || !stack || !a || !a->stack || !b || !b->stack)
	{
		free_vars(a, b, stack);
		write(2, "Error\n", 6);
		return (0);
	}
	sort(a, b);
	free_vars(a, b, stack);
}

// valgrind --leak-check=full --show-leak-kinds=all ./push_swap 

// ARG=""; ./push_swap $ARG | ./checker_Mac $ARG

// vis: re
//	@/usr/bin/python3 ./python_visualizer.py 
// `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`