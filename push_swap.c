/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:37:09 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/31 15:14:07 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_args(int option, char **argv, int argc)
{
    int		i;
    t_list	*stack_a;
    t_list	*tmp;
	char	**elem;
	int		int_v;

    i = 1;
    stack_a = malloc(sizeof(t_list));
    stack_a->next = NULL;
    if (!stack_a || !ft_strlen(argv[1]))
        return;
    if (option == 2)
	{
		i = 0;
		elem = ft_split(argv[1], ' ');
	}
    else
        elem = argv;
    stack_a->content = ft_atoi(elem[i++]);
	printf("int_v: %d\n", stack_a->content);
    while (i < argc)
	{
		
		int_v = ft_atoi(elem[i]);
		printf("int_v: %d\n", ft_atoi(elem[i]));
		tmp = ft_lstnew(int_v);
		if (!tmp)// || int_v == 0 && elem[i][0] == '0'))
			return ;
        ft_lstadd_back(&stack_a, tmp, i);
		tmp = NULL;
		i++;
	}
    return ;
}


int main(int argc, char **argv)
{
	if (argc <= 1 || !argv)
	{
		perror("Invalid arguments");
		return (1);
	}
	else
		check_args((argc == 2) + 1, argv, argc);
	return (0);
}
