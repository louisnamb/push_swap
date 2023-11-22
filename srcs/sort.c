/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:40 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/21 15:38:16 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix(t_list **sa, t_list **sb, t_gen *main, int bitmask)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(sa, main);
	b_len = stack_len(sb, main);
	while (b_len)
	{
		reverse_rotate(sb, main, 1);
		if ((*sb)->content & bitmask)
		{
			push(sb, sa, main);
			rotate(sa, sb, main, 1);
		}
		b_len--;
	}
	while (a_len)
	{
		if ((*sa)->content & bitmask)
			rotate(sa, sb, main, 1);
		else
			push(sa, sb, main);
		a_len--;
	}
	return ;
}

void	sort_three(t_list **sa, t_list **sb, t_gen *main)
{
	if ((*sa)->content < (*sa)->prev->content)
	{
		swap(sa, sb, main);
		if (!is_sorted(sa))
			rotate(sa, sb, main, 1);
		if (is_sorted(sa))
			return ;
	}
	if ((*sa)->content > (*sa)->prev->content)
	{
		(void)sb;
		if ((*sa)->next->content > (*sa)->prev->content
			&& (*sa)->next->content < (*sa)->content)
			swap(sa, sb, main);
		if ((*sa)->next->content > (*sa)->content)
			reverse_rotate(sa, main, 1);
		else
			rotate(sa, sb, main, 1);
	}
	return ;
}

void	sort_five(t_list **sa, t_list **sb, t_gen *main)
{
	int		i;
	t_list	*tmp;
	t_list	*min;
	t_list	*max;

	i = 1;
	min = (*sa);
	max = (*sa);
	tmp = (*sa);
	while (tmp != (*sa) || i == 1)
	{
		i++;
		if (tmp->content > max->content)
			max = tmp;
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	if (min->index > ((*sa)->prev->index / 2) + 1)
	{
		while (min != (*sa))
			reverse_rotate(sa, main, 1);
	}
	else
	{
		while (min != (*sa))
			rotate(sa, sb, main, 1);
	}
	if (max->index >= ((*sa)->prev->index / 2) + 1)
	{
		while (max != (*sa))
			reverse_rotate(sa, main, 1);
	}
	else
	{
		while (max != (*sa))
			rotate(sa, sb, main, 1);
	}
	push(sa, sb, main);
	if ((*sa)->prev->index == 4)
		push(sa, sb, main);
	sort_three(sa, sb, main);
	push(sb, sa, main);
	push(sb, sa, main);
	rotate(sa, sb, main, 1);
	return ;
}

void	offset(t_list **stack_a, t_list **stack_b, t_gen *main)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = (*stack_a);
	if (main->len > 6)
	{
		(*stack_a)->content -= main->offset;
		while (*stack_b)
		{
			(*stack_b)->content -= main->offset;
			push(stack_b, stack_a, main);
		}
	}
	else
	{
		while (tmp != (*stack_a) || i == 1)
		{
			tmp->content -= main->offset;
			tmp = tmp->next;
			i++;
		}
	}
}

void	sort_which(t_list **stack_a, t_list **stack_b, t_gen *main)
{
	int bitmask;
	int	num_bits;

	bitmask = 1;
	num_bits = biggest_node(stack_a, stack_b, main);
	if (is_sorted(stack_a))
		return ;
	if (main->len <= 3)
		sort_three(stack_a, stack_b, main);
	else if (main->len <= 5)
		sort_five(stack_a, stack_b, main);
	else
	{
		while (num_bits > 0)
		{
			radix(stack_a, stack_b, main, bitmask);
			bitmask = bitmask * 2;
			num_bits--;
		}
	}
	offset(stack_a, stack_b, main);
	return ;
}
/*
	if (is_sorted(stack_a) && stack_len(stack_a, main) == main->len)
		printf("\x1b[32mSUCCESS!\x1b[0m\n");
	else
		printf("\x1b[31mFAILURE!\x1b[0m\n");
	printlist(stack_a, main->len, 'a');
*/