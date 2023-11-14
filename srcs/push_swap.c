/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:37:09 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/14 14:21:57 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		printlist(t_list **stack, int len, int a_or_b)
{
    int     i;
    t_list  *tmp;

    i = 0;
	(void)len;
    tmp = (*stack);
    if (!stack || !*stack)
	{
		printf("EMPTY STACK\n");
		printf("----\n    %c\n", a_or_b);
		printf("---------------\n");
        return (0);
	}
    do
    {
		printf("[%zu] %d\n", tmp->index, tmp->content);
        i++;
        tmp = tmp->next;
    }
	while (tmp != (*stack));
	printf("----\n    %c (%d)\n", a_or_b, a_or_b == 'a');
	return (i);
}
// int		printlist(t_list **stack, t_list **stack_b, int a_or_b)
// {
//     int     i;
//     t_list  *tmp;
// 	t_list	*tmp_b;

//     i = 0;
//     tmp = (*stack);
// 	(void)a_or_b;
//     if (!stack || !*stack || !stack_b || !(*stack_b))
// 	{
// 		printf("EMPTY STACK\n");
// 		printf("----\n    %c\n", 'b');
// 		printf("---------------\n");
//         return (0);
// 	}
// 	tmp_b = (*stack_b);
//     do
//     {
// 		printf("[%zu] %d\t\t\t[%zu] %d\n", tmp->index, tmp->content, tmp_b->index, tmp_b->content);
//         i++;
//         tmp = tmp->next;
// 		tmp_b = tmp_b->next;
//     }
// 	while (tmp != (*stack) && tmp_b != (*stack_b));
// 	printf("----\n    %c\t\t\t----\n    %c\n", 'a', 'b');
// 	printf("---------------\n");
// 	return (i);
// }

t_list	*create_stacks(int option, char **argv)
{
    size_t	i;
    t_list	*stack_a;
    t_list	*tmp;
	char	**elem;

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
		tmp = ft_lstnew(ft_atoi(elem[i]));
		if (!tmp)
			return (&(t_list){NULL, 0, 0, NULL});
        if (ft_lstadd_back(&stack_a, tmp, i + (option == 2)))
		{
			free_stack(&stack_a);
			return (&(t_list){NULL, 0, 0, NULL});
		}
	//	printf("stack_a: %d\n", stack_a->content);
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
	t_gen	*main;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	main = malloc(sizeof(t_gen));
	main->len = error_check(argv, argc);
	//printf("main->len: %d\n", main->len);
	if (argc <= 1 || !argv)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	if (main->len)
	{
		stack_a = create_stacks((argc == 2) + 1, argv);
		if (!stack_a->prev && !stack_a->next && !stack_a->content && !stack_a->index)
		{
			perror("Error\n");
			exit(EXIT_FAILURE);
			return (0);
		}
		sort_which(&stack_a, &stack_b, main);
	}
	free_stack(&stack_a);
	return (0);
}