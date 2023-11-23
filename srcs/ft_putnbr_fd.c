/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:05:04 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/23 13:06:04 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	return (write(fd, &c, 1));
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	sum;
	int	len;

	len = 0;
	sum = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	else
	{
		len = ft_strlen(s);
		if (!s || !fd)
			return (0);
		return (write(fd, &*s, len));
	}
}

/*
#include <unistd.h>
#include <stdio.h>

int main()
{
    int b = -234;
    int d = 1; 
    printf("%c\n", *ft_putnbr_fd(b, d));
}*/
