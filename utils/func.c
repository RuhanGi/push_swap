/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:06:28 by mgoltay           #+#    #+#             */
/*   Updated: 2023/01/16 15:36:36 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s2[i] - s1[i]);
}

char	*ft_strdup(const char *s)
{
	char			*obj;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	obj = (char *)malloc(sizeof(char) * len + 1);
	if (!obj)
		return (NULL);
	i = 0;
	while (i < len)
	{
		obj[i] = s[i];
		i++;
	}
	obj[i] = '\0';
	return (obj);
}
