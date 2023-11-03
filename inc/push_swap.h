/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:21:17 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/03 14:16:58 by lnambaji         ###   ########.fr       */
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

typedef struct  general {
    int len;
}   t_general;

void	check_args(int option, char **argv, int argc);
void    sort_which(t_list **stack_a, t_list **stack_b, t_general *main);
int		printlist(t_list **stack_a, int len, int a_or_b);
void    swap(t_list **stack_a, t_list **stack_b, t_general *main);
void	push(t_list **stack_a, t_list **stack_b, t_general *main);
int     stack_len(t_list **stack);


#endif