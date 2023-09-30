/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:04:24 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/16 15:11:44 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	get_median(int *a, int size)
{
	if (size % 2)
		return (a[size / 2]);
	return (a[size / 2 - 1] + 0.5 * (a[size / 2] - a[size / 2 - 1]));
}

int	*sorted_array(t_stack *a)
{
	int	*list;
	int	i;
	int	j;

	list = malloc(sizeof(int) * (a->top + 1));
	i = -1;
	while (++i <= a->top)
		list[i] = a->stack[i];
	i = 0;
	while (i < a->top)
	{
		j = i + 1;
		while (j <= a->top)
			if (list[i] > list[j++])
				swap(&list[i], &list[j - 1]);
		i++;
	}
	return (list);
}

void	fmedian(t_stack *a, float *mid_limit, float *limit)
{
	int	*list;

	list = sorted_array(a);
	if ((a->top + 1) > 2 * MAX_CHUNKSIZE)
	{
		*mid_limit = get_median(list, MAX_CHUNKSIZE);
		*limit = list[MAX_CHUNKSIZE];
	}
	else
	{
		*mid_limit = get_median(list, (a->top + 1) / 2);
		*limit = get_median(list, a->top + 1);
	}
	if (a->top == 0)
		*mid_limit = *limit;
	free(list);
}

int	min_up(t_stack *a, int *up)
{
	int	i;
	int	minindex;

	i = 0;
	minindex = 0;
	while (++i <= a->top)
		if (a->stack[minindex] >= a->stack[i])
			minindex = i;
	if (minindex < (a->top + 1) / 2)
		*up = 0;
	else
		*up = 1;
	return (a->stack[minindex]);
}
