/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:50 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/30 17:14:28 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_list;
	int		pos = 0;

	if (!lst)
		return ;
	if (*lst)
	{
		new_list = *lst;
		while (new_list->next)
		{
			printf("%d: content: %d\n", pos, new_list->content);
			new_list = new_list->next;
			pos++;
		}
		new_list->next = new;
	}
	else
		*lst = new;
}
