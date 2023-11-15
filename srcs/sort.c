/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:40 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/15 16:07:28 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix(t_list **sa, t_list **sb, t_gen *main, int bitmask)
{
	int		a_len;
	int		b_len;

	if (!sa || !(*sa))
		return ;
	a_len = stack_len(sa, main);
	b_len = stack_len(sb, main);
	while (b_len)
	{
		reverse_rotate(sb, main);
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
			reverse_rotate(sa, main);
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
		sort_three(stack_a, stack_b, main);
	else
	{
		while (num_bits > 0)
		{
		//	printf("\x1b[32m---------------\x1b[0m\n");
		//	printf("\x1b[31m---------------\x1b[0m\n\n");
		//	printf("bitmask: %d\n", bitmask);
			radix(stack_a, stack_b, main, bitmask);
			bitmask = bitmask * 2;
			num_bits--;
		}
		while (*stack_b)
			push(stack_b, stack_a, main);
		//else
		//	printf("not sorted\n");
	}
//	if (is_sorted(stack_a) && stack_len(stack_a, main) == main->len)
//		printf("\x1b[32mSUCCESS!\x1b[0m\n");
//	else
//		printf("\x1b[31mFAILURE!\x1b[0m\n");
//	printlist(stack_a, main->len, 'a');
//	printlist(stack_b, main->len, 'b');
//	printf("len a: %d len b: %d main: %d\n", stack_len(stack_a, main), stack_len(stack_b, main), main->len);
	return ;
}