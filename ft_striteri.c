/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:02:32 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/30 15:06:22 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char my_func(unsigned int i, char str)
{
    printf("My inner function: index = %d and %c\n", i, str);
    return (str - 32);
}

int main()
{
    char str[10] = "hello.";
    printf("The str is %s\n", str);
    char *result = ft_striteri(str, my_func);
    printf("The result is %s\n", result);
    return 0;
}*/
