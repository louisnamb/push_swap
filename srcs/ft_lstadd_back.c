/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:50 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/08 11:21:10 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	ft_lstadd_back(t_list **start, t_list *new_node, size_t index)
{
    t_list  *end;

    if (!start || !new_node)
        return;
    if (*start)
    {
        end = (*start)->prev;//make end equal the end node
        end->next = new_node;//make end node point to the new node
        new_node->next = *start;//make the new node point up to the start node
        new_node->index = index;//update index
        new_node->prev = end;//make the new nodes prev point above at the original end node
        (*start)->prev = new_node;//make the start node point to the new end node called new node
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