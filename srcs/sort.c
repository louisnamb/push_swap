/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:40 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/08 13:15:24 by lnambaji         ###   ########.fr       */
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

void    sort_three(t_list **stack_a, t_general *main)
{
    t_list  *tmp;

    tmp = (*stack_a);
    if (tmp->content > tmp->next->content && tmp->prev->content > tmp->content)
        swap(&tmp, stack_a, main);//swap a;
  //  else if (tmp->s)
    return ;
}

void    sort_which(t_list **stack_a, t_list **stack_b, t_general *main)
{
    printlist(stack_a, main->len, 'a');
    printf("here %d\n", main->len);
    if (main->len == 1)
        return ;
    else if (main->len == 3)
    {
        push(stack_a, stack_b, main);
    }
        //sort_three(stack_a, stack_b, main);
        //swap(stack_a);
//    printf("<---//--->\n");
 //   printlist(stack_a, main->len);
    printlist(stack_b, main->len, 'b');
    printlist(stack_a, main->len, 'a');
    return ;
}