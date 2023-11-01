/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   putchars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:07:22 by lnambaji          #+#    #+#             */
/*   Updated: 2023/04/06 13:13:43 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../inc/libft.h"

int	ft_pputnbr_fd(int n, int fd, int total, int *sum)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else if (n < 0)
	{
		total += ft_putchar_fd('-', fd);
		ft_pputnbr_fd(-n, fd, total, sum);
	}
	else if (n >= 10)
	{
		total++;
		ft_pputnbr_fd(n / 10, fd, total, sum);
		total += ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		*sum = total;
		total += ft_putchar_fd(n + '0', fd);
	}
	return (*sum + 1);
}
