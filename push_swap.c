/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:37:09 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/30 17:13:30 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_args(int option, char **argv)
{
	int     i;
	t_list  *stack_a;
	char	**elem;
	int		int_v;

	i = -1;
	stack_a = malloc(sizeof(t_list));
	stack_a->next = NULL;
	if (!stack_a)
		return ;
	if (option == 1)
	{
		if (ft_strlen(*argv) > 1)
		{
			elem = ft_split(argv[1], ' ');
			stack_a->content = ft_atoi(elem[0]); 
			while (elem[++i])
			{
				int_v = ft_atoi(elem[i]);
				ft_lstadd_back(&stack_a, ft_lstnew(int_v));
			}
		}
	}
	else
	{
		stack_a->content = ft_atoi(argv[1]);
		while (argv[++i])
		{
			int_v = ft_atoi(argv[i]);
			ft_lstadd_back(&stack_a, ft_lstnew(int_v));
		}
	}
	return ;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		perror("Invalid arguments");
		return (1);
	}
	else
	{
		if (argc == 2)
			check_args(1, argv);
		else
			check_args(2, argv);
	}
	return (0);
}