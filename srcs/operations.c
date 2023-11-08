/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:08:48 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/08 15:06:12 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

// Does swap for the first argument
void    swap(t_list **stack_a, t_list **stack_b, t_gen *main)
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
	update_index(stack_a);
	printf("sa\n");
	return ;
}

/*
pb (push b): Take the first element at the top of a 
and put it at the top of b. Do nothing if a is empty.
*/

//stack_a->next pointers below it
//stack_a->prev points to the above it
void	push(t_list **stack_a, t_list **stack_b, t_gen *main)//does push_b
{
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
    (*stack_a)->next->prev = (*stack_a)->prev;//make the second node point to the bottom node
    (*stack_a)->prev->next = (*stack_a)->next;//make the bottom node point to the second node
	(*stack_a) = (*stack_a)->next;
    if (main->len == stack_len(stack_a) && !(*stack_b)) {
        tmp->prev = tmp;
        tmp->next = tmp;
    }
	                                                                                            else {
        tmp->next = (*stack_b);//put tmp above stack_b
        tmp->prev = (*stack_b)->prev;//make tmp prev point to the bottom node
        (*stack_b)->prev->next = tmp;//make bottom node point to top node
		(*stack_b)->prev = tmp;//the original top node point to tmp
    }
	(*stack_b) = tmp;//update tmp as the top node
	update_index(stack_a);
	update_index(stack_b);
	printf("pa");
	return ;
}

/*
rotate ra:
	shift all the elements of the stack by one:
4		2	
2	->	3
3		4
*/

void	update_index(t_list **stack)
{
    int     i;
    t_list  *tmp;

    i = 1;
    tmp = (*stack);
    if (!stack || !*stack)
        return ;
    while (tmp != (*stack) || i == 1)
    {
		tmp->index = i;
        i++;
        tmp = tmp->next;
    }
    return ;
}

/*swaps first argument given*/
void	rotate(t_list **stack_a, t_list **stack_b, t_gen *main)
{
	(void)main;
	(void)stack_b;
	if (!(*stack_a))
		return ;
	(*stack_a) = (*stack_a)->next;
	update_index(stack_a);
	printf("ra\n");
	return ;
}

void	reverse_rotate(t_list **stack_a, t_list **stack_b, t_gen *main)
{
	(void)main;
	(void)stack_b;
	if (!(*stack_a))
		return ;
	(*stack_a) = (*stack_a)->prev;
	update_index(stack_a);
	printf("rra\n");
	return ;
}

void    both(t_list **sa, t_list **sb, t_gen *m, void(*func)(t_list **, t_list **, t_gen *))
{
	func(sa, sb, m);
	func(sb, sa, m);
	return ;
}