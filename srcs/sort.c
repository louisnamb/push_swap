/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:40 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/28 14:30:08 by lnambaji         ###   ########.fr       */
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
	if (is_sorted(sa))
		return ;
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

void	sort_four(t_list **sa, t_list **sb, t_gen *main)
{
	int		i;
	t_list	*tmp;
	t_list	*min;

	i = 1;
	min = (*sa);
	tmp = (*sa);
	while (tmp != (*sa) || i++ == 1)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	find_min_max(min, sa, sb, main);
	push(sa, sb, main);
	sort_three(sa, sb, main);
	push(sb, sa, main);
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
	while (tmp != (*sa) || i++ == 1)
	{
		if (tmp->content > max->content)
			max = tmp;
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	find_min_max(min, sa, sb, main);
	push(sa, sb, main);
	sort_four(sa, sb, main);
	push(sb, sa, main);
	return ;
}

void	sort_which(t_list **stack_a, t_list **stack_b, t_gen *main)
{
	int	bitmask;
	int	num_bits;

	bitmask = 1;
	num_bits = biggest_node(stack_a, stack_b, main);
	if (is_sorted(stack_a) || main->len == 1)
		return ;
	if (main->len <= 3)
		sort_three(stack_a, stack_b, main);
	else if (main->len == 4)
		sort_four(stack_a, stack_b, main);
	else if (main->len == 5)
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