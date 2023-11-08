/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:40 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/08 16:14:27 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     stack_len(t_list **stack)
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
		tmp = tmp->next;
	}
	return (i);
}

void    sort_three(t_list **sa, t_list **sb, t_gen *main)
{
	if ((*sa)->content < (*sa)->prev->content)
	{
		swap(sa, sb, main);
		if (!is_sorted(sa))
		   rotate(sa, sb, main);
		if (is_sorted(sa))
			return ;
	}
	if ((*sa)->content > (*sa)->prev->content)
	{
		(void)sb;
		if ((*sa)->next->content > (*sa)->prev->content && (*sa)->next->content < (*sa)->content)
			swap(sa, sb, main);
		if ((*sa)->next->content > (*sa)->content)
			reverse_rotate(sa, sb, main);
		else
			rotate(sa, sb, main);
	}
	return ;
}

void    sort_which(t_list **stack_a, t_list **stack_b, t_gen *main)
{
	if (is_sorted(stack_a))
		return ;
//	printlist(stack_a, main->len, 'a');
//	printf("here %d\n", main->len);
	if (main->len <= 3)
	{
		sort_three(stack_a, stack_b, main);
		if (is_sorted(stack_a)) {
			printf("\x1b[32mSUCCESS!\x1b[0m\n");
		} else {
			printf("\x1b[31mFAILURE!\x1b[0m\n");
		}
	}
//	printlist(stack_b, main->len, 'b');
 //   printlist(stack_a, main->len, 'a');
	return ;
}