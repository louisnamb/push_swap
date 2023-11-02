/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:04:04 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/30 16:23:39 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s)
		write(fd, &*s++, 1);
}

int main()
{
	const char *a = "hello";
	int b = 1;
	printf("%c", ft_putstr_fd(a, b));
	return (0);
}*/