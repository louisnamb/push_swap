/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:08:48 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/08 13:05:03 by lnambaji         ###   ########.fr       */
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

//stack_a->next pointers below it
//stack_a->prev points to the bottom
void	push(t_list **stack_a, t_list **stack_b, t_general *main)//does push_b
{
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
//	if (*stack_a)
//		(*stack_a)->prev = NULL;
    (*stack_a)->next->prev = (*stack_a)->prev;//make the second node point to the bottom node
    (*stack_a)->prev->next = (*stack_a)->next;//make the bottom node point to the second node
	(*stack_a) = (*stack_a)->next;
  //  *stack_a = (*stack_a)->next;//make stack_a point to the second node
    if (main->len == stack_len(stack_a) && !(*stack_b)) {
        // Stack_a is still at its original length
        tmp->prev = tmp;
        tmp->next = tmp;
    }
	                                                                                            else {
        tmp->next = (*stack_b);//put tmp above stack_b
        tmp->prev = (*stack_b)->prev;//make tmp prev point to the bottom node
        (*stack_b)->prev->next = tmp;//make bottom node point to top node
		(*stack_b)->prev = tmp;//the original top node point to tmp
    }
	printf("main->len: %d stack_len: %d\n", main->len, stack_len(stack_a));
    // Update stack_a's top node
	(*stack_b) = tmp;//update tmp as the top node
}
//void    both(t_list **stack_a, t_list **stack_b, (void)func(void **)(void **))