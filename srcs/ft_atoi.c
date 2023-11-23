/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:51:58 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/23 13:08:31 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <limits.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	chckspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (chckspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (ret > INT_MAX)
			return (-1);
		else if (ret < INT_MIN)
			return (0);
	}
	return ((int)ret);
}
/*
#include <stdio.h>

int main()
{
	int p;ma
	int i = 0;
	int j;

	const char s1arr[15][57] = {" \t\v\n\r\f123",
	"0","-1000043",
"+0000000000000000000000000000000000000000000000000000123",
	"    123","--123","-+123","+-123","++123","- 123",
	"+ 123","+\n123","1209","12/3","12;3"};
	while (i < 22)
	{
		p = ft_atoi(s1arr[i]);
		j = atoi(s1arr[i]);
		if (p == j)
			printf("correct: %d == %d\n", p, j);
		else
			printf("%d) Input given: %s:\n\tExpected: %d\n\tGot: %d\n", 
			i, s1arr[i], j, p);
		i++;		
	}
    return (0);
}
*/