/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:30:23 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/01 15:50:23 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

t_list	*create_stacks(int option, char **argv);
void	ft_lstadd_back(t_list **start, t_list *new_node, int index);