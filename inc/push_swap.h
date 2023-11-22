/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:21:17 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/15 11:41:34 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/ft_printf.h"
#include "../inc/libft.h"
#include <limits.h>

typedef struct  general {
    int len;
    int offset;
}   t_gen;

t_list		*ft_lstnew(int content, t_gen *main);
void	check_args(int option, char **argv, int argc);
void    sort_which(t_list **stack_a, t_list **stack_b, t_gen *main);
int		printlist(t_list **stack, int len, int a_or_b);
void    swap(t_list **stack_a, t_list **stack_b, t_gen *main);
void	push(t_list **stack_a, t_list **stack_b, t_gen *main);
void	rotate(t_list **stack_a, t_list **stack_b, t_gen *main, int yes);
void	reverse_rotate(t_list **stack_a, t_gen *main, int yes);//, t_list **stack_b, t_gen *main);
int     stack_len(t_list **stack, t_gen *main);
int     is_repeating(t_list **stack, t_list *new_node);
void	sort_five(t_list **sa, t_list **sb, t_gen *main);
void	update_index(t_list **stack, t_gen *main);
int     is_sorted(t_list **stack_a);
int	ft_atol(char	*str, t_gen *main);
int     biggest_node(t_list **sa, t_list **sb, t_gen *main);
void    free_stack(t_list **stack, t_gen *main);
void	radix(t_list **sa, t_list **sb, t_gen *main, int bitmask);

#endif