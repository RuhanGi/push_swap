/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:09:33 by mgoltay           #+#    #+#             */
/*   Updated: 2025/02/21 16:52:04 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void	s(t_stack *s, int is_b)
{
	if (!is_b)
		ft_putstr("sa\n");
	else if (is_b == 1)
		ft_putstr("sb\n");
	if (s->top < 1)
		return ;
	swap(&s->stack[s->top - 1], &s->stack[s->top]);
}

void	p(t_stack *s, int is_b, t_stack *src)
{
	if (!is_b)
		ft_putstr("pa\n");
	else if (is_b == 1)
		ft_putstr("pb\n");
	if (src->top < 0)
		return ;
	s->top++;
	s->stack[s->top] = src->stack[src->top];
	src->top--;
}

void	r(t_stack *s, int is_b)
{
	int	i;

	if (!is_b)
		ft_putstr("ra\n");
	else if (is_b == 1)
		ft_putstr("rb\n");
	if (s->top < 1)
		return ;
	i = s->top + 1;
	while (--i > 0)
		swap(&s->stack[i], &s->stack[i - 1]);
}

void	rr(t_stack *s, int is_b)
{
	int	i;

	if (!is_b)
		ft_putstr("rra\n");
	else if (is_b == 1)
		ft_putstr("rrb\n");
	if (s->top < 1)
		return ;
	i = -1;
	while (++i < s->top)
		swap(&s->stack[i], &s->stack[i + 1]);
}
