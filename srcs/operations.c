/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:08:48 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/21 13:46:07 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list **stack_a, t_list **stack_b, t_gen *main)
{
	t_list	*first;
	int		tmp;

	(void)(*stack_b);
	if (main->len <= 1)
		return ;
	tmp = (*stack_a)->content;
	first = (*stack_a)->next;
	(*stack_a)->content = first->content;
	first->content = tmp;
	ft_printf("s%c\n", (*stack_a)->id);
	return ;
}

void	push(t_list **stack_a, t_list **stack_b, t_gen *main)
{
	t_list	*tmp;

	if (!(*stack_a) || !stack_a)
		return ;
	tmp = (*stack_a);
	if (stack_len(stack_a, main) > 1
		&& stack_len(stack_b, main) != main->len - 1)
	{
		(*stack_a)->next->prev = (*stack_a)->prev;
		(*stack_a)->prev->next = (*stack_a)->next;
		(*stack_a) = (*stack_a)->next;
	}
	else
		*stack_a = NULL;
	if ((*stack_b) == NULL)
	{
		tmp->prev = tmp;
		tmp->next = tmp;
		tmp->id = 'b';
	}
	else
	{
		tmp->next = (*stack_b);
		tmp->prev = (*stack_b)->prev;
		tmp->id = (*stack_b)->id;
		(*stack_b)->prev->next = tmp;
		(*stack_b)->prev = tmp;
	}
	(*stack_b) = tmp;
	if (stack_len(stack_a, main) > 1)
		update_index(stack_a, main);
	update_index(stack_b, main);
	ft_printf("p%c\n", (*stack_b)->id);
	return ;
}

void	rotate(t_list **stack_a, t_list **stack_b, t_gen *main, int yes)
{
	(void)main;
	(void)stack_b;
	if (!(*stack_a))
		return ;
	(*stack_a) = (*stack_a)->next;
	update_index(stack_a, main);
	if (yes)
		ft_printf("r%c\n", (*stack_a)->id);
	return ;
}

void	reverse_rotate(t_list **stack_a, t_gen *main, int yes)
{
	if (!(*stack_a))
		return ;
	(*stack_a) = (*stack_a)->prev;
	update_index(stack_a, main);
	if (yes)
		ft_printf("rr%c\n", (*stack_a)->id);
	return ;
}
