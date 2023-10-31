/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:37:09 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/31 15:44:39 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	create_stacks(int option, char **argv)
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
    while (elem[i])
	{
		int_v = ft_atoi(elem[i]);
		tmp = ft_lstnew(int_v);
		if (!tmp)
			return ;
        ft_lstadd_back(&stack_a, tmp, i);
		tmp = NULL;
		i++;
	}
    return ;
}

int		error_check(char **argv, int argc)
{
	char	**elem;
	int		i;
	int		j;

	j = 0;
	i = 1;
	if (argc == 2)
	{
		i = 0;
		elem = ft_split(argv[1], ' ');
	}
	else
		elem = argv;
	while (elem[i])
	{
		j = 0;
		while (elem[i][j])
		{
			if (!ft_isalpha(elem[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	if (argc <= 1 || !argv || !error_check(argv, argc))
	{
		perror("Invalid arguments");
		return (1);
	}
	create_stacks((argc == 2) + 1, argv);
	return (0);
}
