/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:08:48 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/03 14:36:11 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    swap(t_list **stack_a, t_list **stack_b, t_general *main)
{
	t_list  *first;
	int     tmp;

	(void)(*stack_b);
	if (main->len <= 1)
		return ;
	tmp = (*stack_a)->content;
	first = (*stack_a)->next;
	(*stack_a)->content = first->content;
	first->content = tmp;
	return ;
}

/*
pb (push b): Take the first element at the top of a 
and put it at the top of b. Do nothing if a is empty.
*/
void	push(t_list **stack_a, t_list **stack_b, t_general *main)//does push_b
{
	t_list	*tmp;

	tmp = (*stack_a);
	if (!tmp)
		return ;
	printf("main->len: %d stack_len: %d\n", main->len, stack_len(stack_a));
	if (main->len == stack_len(stack_a))//if stack_a is still the original length i.e, we haven't done anything
	{
		(*stack_b) = malloc(sizeof(t_list));
		if (!(*stack_b))
			return ;
		tmp->next = NULL;
		tmp->prev = NULL;//detach the top node
		(*stack_b) = tmp;//make stack_b point to it
	}
	else
	{
		tmp = (*stack_a);
		tmp->prev = (*stack_b);
		tmp->next = (*stack_b);
	}
	(*stack_a)->prev->next = (*stack_a)->next;//make the "bottom" node point to the second node
	(*stack_a)->next->prev = (*stack_a)->prev;//make the second's node previous point to the bottom node
	(*stack_a) = (*stack_a)->next;
	return ;
}

//void    both(t_list **stack_a, t_list **stack_b, (void)func(void **)(void **))