/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:50:28 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/08 16:16:07 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    free_stack(t_list **stack)
{
	int     i;
	t_list  *tmp;
    t_list  *next;

	i = 1;
	tmp = (*stack);
	if (!stack || !*stack)
		return ;
	while (tmp != (*stack) || i == 1)
	{
		next = tmp->next;
        free(tmp);
        tmp = next;
		i++;
	}
    return ;
}

int    is_repeating(t_list **stack, t_list *new_node)
{
	int     i;
	t_list  *tmp;

	i = 1;
	tmp = (*stack);
	if (!stack || !*stack)
		return (0);
	while (tmp != (*stack) || i == 1)
	{
		i++;
        if (new_node->content == tmp->content)
            return (1);
		tmp = tmp->next;
	}
	return (0);
}
