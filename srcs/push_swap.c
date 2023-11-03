/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:37:09 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/03 14:25:06 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		printlist(t_list **stack_a, int len, int a_or_b)
{
	t_list	*iterator;

	if (*stack_a)
	{
		iterator = *stack_a;
		while (iterator && len)
		{
			printf("[%zu] %d\n", iterator->index, iterator->content);
			iterator = iterator->next;
			len--;
		}
	}
	printf("----\n    %c\n", a_or_b);
	printf("---------------\n");
	return (0);
}

t_list	*create_stacks(int option, char **argv)
{
    size_t	i;
    t_list	*stack_a;
    t_list	*tmp;
	char	**elem;
	int		int_v;

    i = 1;
    stack_a = malloc(sizeof(t_list));
    stack_a->next = stack_a;
	stack_a->prev = stack_a;
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
	stack_a->index = 1;
    while (elem[i])
	{
		int_v = ft_atoi(elem[i]);
		tmp = ft_lstnew(int_v);
		if (!tmp)
			return (&(t_list){NULL, 0, 0, NULL});
        ft_lstadd_back(&stack_a, tmp, i + (option == 2));
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
	t_list		*stack_a;
	t_general	*main;

	main = malloc(sizeof(t_general));
	main->len = error_check(argv, argc);
	if (argc <= 1 || !argv)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
//	stack_a = malloc(sizeof(t_list));
	if (main->len)
	{
		stack_a = create_stacks((argc == 2) + 1, argv);
	//	stack_b = malloc(sizeof(t_list));
		sort_which(&stack_a, &stack_a, main);
	}
	printlist(&stack_a, main->len, 'a');
	
	//free everything
	return (0);
}