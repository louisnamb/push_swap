/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:50 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/01 16:19:24 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	ft_lstadd_back(t_list **start, t_list *new_node, int index)
{
    if (!start)
        return;
    if ((*start)->next)
    {
        t_list *end = (*start)->prev;
        end->next = new_node;
        new_node->next = *start;
        new_node->index = index;
        new_node->prev = end;
        (*start)->prev = new_node;
    }
    else
    {
		(*start)->prev = *start;
        (*start)->next = *start;
        (*start)->index = index;
        *start = new_node;
    }
}
