/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:50 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/02 12:57:12 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	ft_lstadd_back(t_list **start, t_list *new_node, size_t index)
{
    if (!start || !new_node)
        return;
    if (*start)
    {
        t_list *end = (*start)->prev;
        end->next = new_node;
        new_node->next = *start;
        new_node->index = index;
        new_node->prev = end;
        (*start)->prev = new_node;
    }
    // else
    // {
	// 	new_node->prev = new_node;
    //     new_node->next = new_node;
    //     new_node->index = index;
    //     *start = new_node;
    // }
  //  printf("back - new_node->index: %zu index: %zu\n", new_node->index, index);
    return ;
}