/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:19:12 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/30 15:44:47 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned int	i;

	i = 0;
	p = (unsigned char *)b;
	while (len--)
		p[i++] = (unsigned char)c;
	return (p);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
   char str[50] = "This is string.h library function";

   printf("%s", memset(str,'$',7));
   printf("\n\n%s", ft_memset(str, '$', 7));

   return(0);
}*/
