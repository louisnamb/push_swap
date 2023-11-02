/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:40 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/02 16:09:39 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     stack_len(t_list **stack)
{
    int     i;
    t_list  *tmp;

    i = 0;
    tmp = (*stack);
    if (!stack)
        return (-1);
    while (tmp->content != (*stack)->content || i == 0)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

void    sort_three(t_list **stack_a, int len)
{
    (void)(*stack_a);
    (void)len;
    return ;
}

void    sort_which(t_list **stack_a, int len)
{
    printlist(stack_a, len);
    if (len == 3)
        swap(stack_a);
        //sort_three(stack_a, stack_b, len);
//    printf("<---//--->\n");
 //   printlist(stack_a, len);
    return ;
}
