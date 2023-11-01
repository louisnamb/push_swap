/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:44:41 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/01 15:00:56 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     sort_three(t_list *stack_a, t_list *stack_b, int len)
{
    (void)len;
    (void)stack_a;
    (void)stack_b;
    return (0);
}

int     sort_five(t_list *stack_a, t_list *stack_b, int len)
{
    (void)len;
    (void)stack_a;
    (void)stack_b;
    return (0);
}

int     sort_all(t_list *stack_a, t_list *stack_b, int len)
{
    (void)len;
    (void)stack_a;
    (void)stack_b;
    return (0);
}


void    sort(t_list *stack_a, t_list *stack_b, int len)
{
    if (len == 3)
        sort_three(stack_a, stack_b, len);
    else if (len == 5)
        sort_five(stack_a, stack_b, len);
    else
        sort_all(stack_a, stack_b, len);
    return ;   
}