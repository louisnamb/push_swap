/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:21:17 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/02 15:42:37 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/ft_printf.h"
#include "../inc/libft.h"
#include <limits.h>

void	check_args(int option, char **argv, int argc);
void    sort_which(t_list **stack_a, int len);
int		printlist(t_list **stack_a, int len);

#endif
