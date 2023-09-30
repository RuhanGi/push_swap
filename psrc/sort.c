/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:02:30 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/18 18:18:52 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_last(t_stack *a, t_stack *b)
{
	if (a->top < 2 || a->stack[0] > a->stack[2])
		s(a, 0);
	else if (a->stack[0] < a->stack[1] && a->stack[1] < a->stack[2])
		s(a, 0);
	else if (a->stack[0] > a->stack[1])
		r(a, 0);
	else if (a->stack[0] < a->stack[1])
		rr(a, 0);
	sort(a, b);
}

void	handle_five(t_stack *a, t_stack *b)
{
	int	min;
	int	num;
	int	up;

	num = 0;
	while (a->top > 2)
	{
		min = min_up(a, &up);
		if (up)
			while (a->stack[a->top] != min)
				r(a, 0);
		else
			while (a->stack[a->top] != min)
				rr(a, 0);
		p(b, 1, a);
		num++;
	}
	sort(a, b);
	while (num-- != 0)
		p(a, 0, b);
}

int	exist(t_stack *a, float limit)
{
	int	i;

	i = -1;
	while (++i <= a->top)
		if (a->stack[i] < limit)
			return (1);
	return (0);
}

int	push_to_b(t_stack *a, t_stack *b, float mid_limit, float limit)
{
	int	chunksize;

	chunksize = 0;
	while (exist(a, limit) && a->top > 2)
	{
		if (a->stack[a->top] < limit)
		{
			p(b, 1, a);
			chunksize++;
			if (b->stack[b->top] < mid_limit)
			{
				if (exist(a, limit) && a->stack[a->top] >= limit)
					dr(a, b, 1);
				else
					r(b, 1);
			}
			if (sorted(a))
				return (chunksize);
		}
		else
			r(a, 0);
	}
	return (chunksize);
}

void	sort(t_stack *a, t_stack *b)
{
	float	limit;
	float	mid_limit;
	int		chunksize;

	if (sorted(a))
		return ;
	if (a->top < 3)
	{
		handle_last(a, b);
		return ;
	}
	if (a->top < 5)
	{
		handle_five(a, b);
		sort(a, b);
		return ;
	}
	fmedian(a, &mid_limit, &limit);
	chunksize = push_to_b(a, b, mid_limit, limit);
	sort(a, b);
	extract(a, b, chunksize);
}
