/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:12:13 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/16 15:10:42 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	execute_move(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		s(a, 2);
	else if (!ft_strcmp(str, "sb\n"))
		s(b, 2);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(str, "pa\n"))
		p(a, 2, b);
	else if (!ft_strcmp(str, "pb\n"))
		p(b, 2, a);
	else if (!ft_strcmp(str, "ra\n"))
		r(a, 2);
	else if (!ft_strcmp(str, "rb\n"))
		r(b, 2);
	else if (!ft_strcmp(str, "rr\n"))
		dr(a, b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rr(a, 2);
	else if (!ft_strcmp(str, "rrb\n"))
		rr(b, 2);
	else if (!ft_strcmp(str, "rrr\n"))
		drr(a, b, 0);
	else
		return (0);
	return (1);
}

int	execute_read(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_move(a, b, line))
			return (0);
		free(line);
		line = get_next_line(0);
	}
	if (sorted(a) && (a->top + 1) == a->size && b->top < 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (1);
}

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
	execute_read(a, b);
	free_vars(a, b, stack);
}
