/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:50:28 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/28 12:49:38 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*free_stack(t_list **stack, t_gen *main)
{
	int		i;
	t_list	*next;
	t_list	*current;

	i = 1;
	if (!*stack)
		return (&(t_list){NULL, 0, 0, ' ', NULL});
	current = *stack;
	while (current != (*stack) || i == 1)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	(*stack) = NULL;
	free(main);
	return (&(t_list){NULL, 0, 0, ' ', NULL});
}

int	is_repeating(t_list **stack, t_list *new_node)
{
	int		i;
	t_list	*tmp;

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

int	biggest_node(t_list **sa, t_list **sb, t_gen *main)
{
	int		i;
	t_list	*tmp;
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
		while (tmp_data > 0 && ++curr_max)
			tmp_data >>= 1;
		if (curr_max > prev_max)
			prev_max = curr_max;
		tmp = tmp->next;
	}
	return (prev_max);
}

int	stack_len(t_list **stack, t_gen *main)
{
	int		i;
	t_list	*tmp;

	i = 0;
	(void)main;
	if (!stack || !(*stack))
		return (0);
	tmp = *stack;
	while (tmp != (*stack) || i == 0)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*tmp;
	int		old;
	int		i;

	i = 1;
	tmp = (*stack_a);
	old = tmp->content;
	if (!stack_a || !(*stack_a))
		return (0);
	while (tmp != (*stack_a) || i == 1)
	{
		i++;
		if (tmp->content < old)
			return (0);
		old = tmp->content;
		tmp = tmp->next;
	}
	return (1);
}
