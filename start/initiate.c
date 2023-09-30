/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:57:59 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/16 15:30:22 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_vars(t_stack *a, t_stack *b, int *stack)
{
	if (a)
		free(a->stack);
	if (a)
		free(a);
	if (b)
		free(b->stack);
	if (b)
		free(b);
	if (stack)
		free(stack);
}

int	*int_arr_dup(int *src, int size)
{
	int	*stack;

	stack = (int *) malloc(sizeof(int) * size);
	if (!stack)
		return (NULL);
	while (size-- > 0)
		stack[size] = src[size];
	return (stack);
}

void	make_stacks(t_stack **a, t_stack **b, int *stack, int size)
{
	*a = (t_stack *) malloc(sizeof(t_stack));
	*b = (t_stack *) malloc(sizeof(t_stack));
	if (!a || !b || !stack)
		return ;
	(*a)->size = size;
	(*a)->top = size - 1;
	(*a)->stack = int_arr_dup(stack, size);
	(*b)->size = size;
	(*b)->top = -1;
	(*b)->stack = int_arr_dup(stack, size);
}

int	check(char *str, int i, long long num)
{
	if (str[i] >= '0' && str[i] <= '9')
	{
		if (num < -2147483648 || num > 2147483647)
			return (0);
	}
	else if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (0);
		if (i > 0 && str[i - 1] != ' ')
			return (0);
	}
	else if (str[i] != ' ')
		return (0);
	return (1);
}

int	applicable(char *str)
{
	int			i;
	int			flag;
	int			sign;
	long long	num;

	i = 0;
	flag = 0;
	sign = 1;
	num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && ++flag)
			num = num * 10 + (str[i] - '0');
		else if (str[i] == '+' || str[i] == '-')
			sign = 44 - str[i];
		else if (str[i] == ' ')
		{
			sign = 1;
			num = 0;
		}
		if (!check(str, i++, num * sign))
			return (0);
	}
	return (flag);
}
