/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:50:28 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/20 15:53:00 by lnambaji         ###   ########.fr       */
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

// void	expected_sort(t_list **sa, t_list **sb, t_gen *main)
// {
// 	int
// 	return ;
// }

int	biggest_node(t_list **sa, t_list **sb, t_gen *main)
{
	int     i;
	t_list  *tmp;
	int		prev_max;
	int		curr_max;
	int		tmp_data;

	i = 1;
	prev_max = 0;
	(void)sb;
	(void)main;
	tmp = (*sa);
	if (!sa || !*sa)
		return (0);
	while (tmp != (*sa) || i++ == 1)
	{
		curr_max = 0;
		tmp_data = tmp->content;
		while (tmp_data > 0)
		{
			tmp_data = tmp_data >> 1;
			curr_max++;
		}
		if (curr_max > prev_max)
			prev_max = curr_max;
		tmp = tmp->next;
	}
	return (prev_max);
}

int     stack_len(t_list **stack, t_gen *main)
{
	int     i;
	t_list  *tmp;

	i = 0;
	(void)main;
	if (!stack || !(*stack))
		return (0);
	tmp = *stack;
	while (tmp != (*stack) || i == 0)// && tmp->next != tmp)// && i <= main->len)
	{
	//	printf("content: %d\n", tmp->content);
		tmp = tmp->next;
		i++;
	}
//	printf("stack_len - i: %d\n", i);
	return (i);
}