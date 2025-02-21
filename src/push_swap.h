/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:00:47 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/18 17:16:09 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# ifndef MAX_CHUNKSIZE
#  define MAX_CHUNKSIZE 75
# endif

typedef struct s_stack
{
	int	top;
	int	size;
	int	*stack;
}	t_stack;

int		applicable(char *str);
void	make_stacks(t_stack **a, t_stack **b, int *stack, int size);
void	free_vars(t_stack *a, t_stack *b, int *stack);
int		*parse(char *argv[], int argc, int *size);

void	fmedian(t_stack *a, float *mid_limit, float *limit);
int		min_up(t_stack *a, int *up);
void	extract(t_stack *a, t_stack *b, int chunksize);
void	sort(t_stack *a, t_stack *b);
int		sorted(t_stack *a);

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_fstrjoin(char *dest, char *src);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);

void	*free_arr(char **strs);

void	swap(int *num1, int *num2);
void	s(t_stack *s, int is_b);
void	ss(t_stack *a, t_stack *b, int print);
void	p(t_stack *s, int is_b, t_stack *src);
void	r(t_stack *s, int is_b);
void	dr(t_stack *a, t_stack *b, int print);
void	rr(t_stack *s, int is_b);
void	drr(t_stack *a, t_stack *b, int print);

#endif