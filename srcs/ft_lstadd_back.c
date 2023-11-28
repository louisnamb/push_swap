/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:50 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/28 14:30:25 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

int	ft_lstadd_back(t_list **start, t_list **new_node, size_t index)
{
	t_list	*end;

	if (!start || !(*new_node) || !(*start))
		return (0);
	if (is_repeating(start, (*new_node)))
		return (1);
	if (*start)
	{
		end = (*start)->prev;
		end->next = (*new_node);
		(*new_node)->next = *start;
		(*new_node)->index = index;
		(*new_node)->id = 'a';
		(*new_node)->prev = end;
		(*start)->prev = (*new_node);
	}
	*new_node = NULL;
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

int	helper_func(int sign, char c, long *num)
{
	int	digit;

	digit = c - '0';
	if (check_num(*num, sign, digit))
	{
		exit(1);
		return (1);
	}
	(*num) = (*num) * 10 + digit;
	return (0);
}
