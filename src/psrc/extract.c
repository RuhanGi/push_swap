/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:56:29 by mgoltay           #+#    #+#             */
/*   Updated: 2025/02/21 16:51:05 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_max_up(t_stack *b, int *up, int *max, int *max2)
{
	int	i;
	int	maxindex;
	int	maxindex2;

	i = 0;
	maxindex = 0;
	while (++i <= b->top)
		if (b->stack[maxindex] < b->stack[i])
			maxindex = i;
	i = 0;
	maxindex2 = 0;
	while (++i <= b->top)
		if (i != maxindex && b->stack[maxindex2] < b->stack[i])
			maxindex2 = i;
	if (maxindex < (b->top + 1) / 2 && maxindex2 < maxindex)
		*up = -2;
	else if (maxindex < (b->top + 1) / 2)
		*up = -1;
	else if (maxindex2 <= maxindex)
		*up = 1;
	else
		*up = 2;
	*max = b->stack[maxindex];
	*max2 = b->stack[maxindex2];
}

void	do_two(t_stack *a, t_stack *b, int up, int max2)
{
	if (up == -2)
		while (max2 != b->stack[b->top])
			rr(b, 1);
	else if (up == 2)
		while (max2 != b->stack[b->top])
			r(b, 1);
	p(a, 0, b);
}

void	extract(t_stack *a, t_stack *b, int chunksize)
{
	int	up;
	int	extracted;
	int	max;
	int	max2;

	up = 1;
	extracted = 0;
	while (extracted++ < chunksize)
	{
		two_max_up(b, &up, &max, &max2);
		if ((up == -2 || up == 2) && ++extracted)
			do_two(a, b, up, max2);
		if (up < 0)
			while (max != b->stack[b->top])
				rr(b, 1);
		if (up > 0)
			while (max != b->stack[b->top])
				r(b, 1);
		p(a, 0, b);
		if (a->stack[a->top - 1] < a->stack[a->top])
			s(a, 0);
	}
}

// compares maxindex and maxindex2:
// if down and i2<i, push both, do swap
// if up and i2>i, push both, do swap

// status of variable up:
// -2 = down but push both
// -1 = down push one only
//  1 =  up  push one only
//  2 =  up  but push both