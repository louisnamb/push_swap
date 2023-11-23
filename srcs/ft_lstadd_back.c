/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:50 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/23 13:07:08 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

int	ft_lstadd_back(t_list **start, t_list *new_node, size_t index)
{
	t_list	*end;

	if (!start || !new_node || !(*start))
		return (0);
	if (is_repeating(start, new_node))
		return (1);
	if (*start)
	{
		end = (*start)->prev;
		end->next = new_node;
		new_node->next = *start;
		new_node->index = index;
		new_node->id = 'a';
		new_node->prev = end;
		(*start)->prev = new_node;
	}
	return (0);
}

t_list	*ft_lstnew(int content, t_gen *main)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content + (int)main->offset;
	node->next = NULL;
	node->id = 'a';
	node->prev = NULL;
	return (node);
}
