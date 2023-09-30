/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:30 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/16 15:43:04 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**argv_join(char *argv[], int argc)
{
	int		i;
	char	*arg;
	char	**strs;

	i = -1;
	if (!argv || !argv[0] || !argv[0][0] || argc <= 0)
		exit(0);
	arg = ft_strdup("");
	while (++i < argc)
	{
		if (!arg || !argv[i] || !applicable(argv[i]))
		{
			free(arg);
			write(2, "Error\n", 6);
			exit(0);
		}
		arg = ft_fstrjoin(arg, " ");
		arg = ft_fstrjoin(arg, argv[i]);
	}
	strs = ft_split(arg, ' ');
	free(arg);
	return (strs);
}

void	*free_arr(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

int	ft_atoi(char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	num = 0;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*(str++) - '0');
	return (num * sign);
}

int	duplicate(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (++j < size)
			if (stack[i] == stack[j])
				return (1);
		i++;
	}
	return (0);
}

int	*parse(char *argv[], int argc, int *size)
{
	char	**strs;
	int		*stack;
	int		i;

	strs = argv_join(argv, argc);
	if (!strs)
		exit(0);
	*size = 0;
	while (strs[*size])
		*size = (*size) + 1;
	stack = (int *) malloc(sizeof(int) * *size);
	if (!stack)
		return (free_arr(strs));
	i = -1;
	while (strs[++i])
		stack[*size - i - 1] = ft_atoi(strs[i]);
	free_arr(strs);
	if (duplicate(stack, *size))
		*size = 0;
	return (stack);
}
