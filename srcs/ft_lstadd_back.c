/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:50 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/21 15:24:33 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

int	ft_lstadd_back(t_list **start, t_list *new_node, size_t index)
{
    t_list  *end;

    if (!start || !new_node || !(*start))
        return (0);
    if (is_repeating(start, new_node))
        return (1);
    if (*start)
    {
        end = (*start)->prev;//make end equal the end node
        end->next = new_node;//make end node point to the new node
        new_node->next = *start;//make the new node point up to the start node
        new_node->index = index;//update index
        new_node->id = 'a';
    //    new_node->sorted_index = 0;
        new_node->prev = end;//make the new nodes prev point above at the original end node
        (*start)->prev = new_node;//make the start node point to the new end node called new node
    }
 //   printf("added: %d\n", new_node->content);
    return (0);
}