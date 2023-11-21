/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:19:34 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/21 15:43:24 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

t_list	*ft_lstnew(int content, t_gen *main)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content + main->offset;
	node->next = NULL;
	printf("new: offset: %d\n", main->offset);
	node->id = 'a';
	node->prev = NULL;
	return (node);
}


/*
get 1 more chickenpox vaccine (varicella)
one more hepatatis b vaccine
*/