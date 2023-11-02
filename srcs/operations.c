/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:08:48 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/02 16:20:25 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    swap(t_list **node, t_list **other)
{
    t_list  *first;
    int     tmp;
    int     i;

    (void)(*other);
    i = stack_len(node);
    if (i <= 1)
        return ;
    tmp = (*node)->content;
    first = (*node)->next;
    (*node)->content = first->content;
    first->content = tmp;
    return ;
}

void    push(t_list **stack_a, t_list **stack_b)
{

}

//void    both(t_list **stack_a, t_list **stack_b, (void)func(void **)(void **))