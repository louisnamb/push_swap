/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:37:09 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/01 16:18:09 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*create_stacks(int option, char **argv)
{
    int		i;
    t_list	*stack_a;
    t_list	*tmp;
	char	**elem;
	int		int_v;

    i = 1;
    stack_a = malloc(sizeof(t_list));
    stack_a->next = NULL;
	stack_a->prev = NULL;
    if (!stack_a || !ft_strlen(argv[1]))
       return (&(t_list){NULL, 0, 0, NULL});
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
			return (&(t_list){NULL, 0, 0, NULL});
        ft_lstadd_back(&stack_a, tmp, i);
		tmp = NULL;
		i++;
	}
    return (stack_a);
}

int		error_check(char **argv, int argc)
{
	char	**elem;
	int		i;
	int		j;

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
			if (!ft_isdigit(elem[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i - (argc == i));
}

int main(int argc, char **argv)
{
	int		len;
	t_list	*stack_a;
	t_list	*stack_b;

	len = error_check(argv, argc);
	if (argc <= 1 || !argv)
	{
		perror("Invalid arguments");
		exit(EXIT_FAILURE);
	}
	stack_b = malloc(sizeof(t_list));
	if (len)
	{
		stack_a = create_stacks((argc == 2) + 1, argv);
	//	sort(stack_a, stack_b, len);
	}
	//free everything
	return (0);
}
