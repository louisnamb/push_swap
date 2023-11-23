/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:40 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/23 15:54:23 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	skip_whitespaces(char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\v'
		|| str[*i] == '\r' || str[*i] == '\f')
		(*i)++;
	if ((str[*i] == '+' || str[*i] == '-') && str[*i + 1])
	{
		if ((str[*i]) == '-')
			*sign *= -1;
		(*i)++;
	}
	return (*i);
}

static int	check_num(long num, int sign, int digit)
{
	if (sign == -1)
		return (((num * -1) <= INT_MIN / 10)
			&& ((digit * sign) < INT_MIN % 10));
	else
		return (num >= INT_MAX / 10 && digit > INT_MAX % 10);
}

int	ft_atol(char	*str, t_gen *main)
{
	int		i;
	long	num;
	int		sign;
	int		digit;

	sign = 1;
	i = 0;
	num = 0;
	skip_whitespaces(str, &i, &sign);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (check_num(num, sign, digit))
				return (1);
			num = num * 10 + digit;
		}
		else if (skip_whitespaces(str, &i, &sign))
			break ;
		else
			return (1);
		i++;
	}
	if (sign == -1 && (num * sign) < main->offset)
		main->offset = (int)num;
	else
		main->offset = 0;
	return (0);
}

void	update_index(t_list **stack, t_gen *main)
{
	int		i;
	t_list	*tmp;
	int		s_len;

	i = 1;
	s_len = stack_len(stack, main);
	tmp = (*stack);
	if (!stack || !*stack)
		return ;
	(void)main;
	while ((tmp != (*stack) || i == 1) && i <= s_len)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	return ;
}

void updatestackb(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	tmp = *stack_a;
	if ((*stack_b) == NULL)
	{
		tmp->prev = tmp;
		tmp->next = tmp;
		tmp->id = 'b';
	}
	else
	{
		tmp->next = (*stack_b);
		tmp->prev = (*stack_b)->prev;
		tmp->id = (*stack_b)->id;
		(*stack_b)->prev->next = tmp;
		(*stack_b)->prev = tmp;
	}
	*stack_b = tmp;
}