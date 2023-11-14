/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:40 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/14 14:20:16 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix(t_list **sa, t_list **sb, t_gen *main, int bitmask)
{
	int		a_len;
	int		b_len;

	if (!sa || !(*sa))
		return ;
	a_len = stack_len(sa);
	b_len = stack_len(sb);
	while (b_len)
	{
		reverse_rotate(sb, sa, main);
		if ((*sb)->content & bitmask)
		{
			push(sb, sa, main);
			rotate(sa, sb, main);
		}
		b_len--;
	}
	while (a_len)
	{
		if ((*sa)->content & bitmask)
			rotate(sa, sb, main);
		else
			push(sa, sb, main);
		a_len--;
	}
	return ;
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
	int bitmask;
	int	num_bits;

	bitmask = 1;
	num_bits = biggest_node(stack_a, stack_b, main);
	if (is_sorted(stack_a))
		return ;
	if (main->len <= 3)
	{
		sort_three(stack_a, stack_b, main);
		if (is_sorted(stack_a)) {
			printf("\x1b[32mSUCCESS!\x1b[0m\n");
		} else {
			printf("\x1b[31mFAILURE!\x1b[0m\n");
		}
	}
	else
	{
		while (num_bits > 0)
		{
			printf("bitmask: %d\n", bitmask);
		//	printf("\033[1;34mBEFORE:[0m\n");
			printlist(stack_a, main->len, 'a');
			printlist(stack_b, main->len, 'b');
			radix(stack_a, stack_b, main, bitmask);
			printf("\033[1;34m----------\n\033[0m\n");
			bitmask = bitmask * 2;
			num_bits--;
		}
	}
	return ;
}