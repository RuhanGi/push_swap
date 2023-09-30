/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:36:15 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/16 14:30:05 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->top)
		if (a->stack[i] < a->stack[i + 1])
			return (0);
	return (1);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	if (print)
		ft_putstr("ss\n");
	s(a, 2);
	s(b, 2);
}

void	dr(t_stack *a, t_stack *b, int print)
{
	if (print)
		ft_putstr("rr\n");
	r(a, 2);
	r(b, 2);
}

void	drr(t_stack *a, t_stack *b, int print)
{
	if (print)
		ft_putstr("rrr\n");
	rr(a, 2);
	rr(b, 2);
}
