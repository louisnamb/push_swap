/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:50 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/31 15:07:17 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new, int index)
{
    if (!lst)
        return;
    if (*lst)
    {
        t_list *new_list = *lst;
        while (new_list->next)
            new_list = new_list->next;
        new_list->next = new;
        new->index = index;
    }
    else
    {
        *lst = new;
		(*lst)->prev = NULL;
        (*lst)->index = index;
    }
}
