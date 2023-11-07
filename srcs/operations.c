/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:08:48 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/07 15:35:53 by lnambaji         ###   ########.fr       */
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

//stack_a->prev pointers below it
//stack_a->next points to the bottom
void	push(t_list **stack_a, t_list **stack_b, t_general *main)//does push_b
{
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	*stack_a = (*stack_a)->prev;
	printf("main->len: %d stack_len: %d\n", main->len, stack_len(stack_a));
	if (!tmp)
		return ;
	if (*stack_a)
		(*stack_a)->prev->prev = NULL;
    if (main->len == stack_len(stack_a)) {
        // Stack_a is still at its original length
        tmp->next = NULL;
        tmp->prev = NULL;
        *stack_b = tmp;
    } else {
        tmp->next = (*stack_b)->prev;
        tmp->prev = (*stack_b);
        (*stack_b)->next = tmp;
        (*stack_b)->prev->next = tmp;
    }

    // Update stack_a's top node
    (*stack_a)->next->prev = (*stack_a)->prev;
    (*stack_a)->prev->next = (*stack_a)->next;
    *stack_a = (*stack_a)->next;
}
//void    both(t_list **stack_a, t_list **stack_b, (void)func(void **)(void **))