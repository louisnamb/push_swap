/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:37:09 by lnambaji          #+#    #+#             */
/*   Updated: 2023/12/19 15:50:52 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	find_min_max(t_list *minmax, t_list **sa, t_list **sb, t_gen *main)
{
	if (minmax->index > ((*sa)->prev->index / 2) + 1)
	{
		while (minmax != (*sa))
			reverse_rotate(sa, main, 1);
	}
	else
	{
		while (minmax != (*sa))
			rotate(sa, sb, main, 1);
	}
	return ;
}

t_list	*initialize_stack_a(size_t *i, char **elem, t_gen *main)
{
	t_list	*stack_a;

	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (&(t_list){NULL, 0, 0, ' ', NULL});
	stack_a->next = stack_a;
	stack_a->content = ft_atoi(elem[(*i)]) + main->offset;
	stack_a->prev = stack_a;
	stack_a->index = 1;
	stack_a->id = 'a';
	(*i)++;
	return (stack_a);
}

t_list	*create_stacks(int option, char **argv, t_gen *main)
{
	size_t	i;
	t_list	*stack_a;
	t_list	*tmp;
	char	**elem;

	i = (option != 2);
	if (option == 2)
		elem = ft_split(argv[1], ' ');
	else
		elem = argv;
	stack_a = initialize_stack_a(&i, elem, main);
	if (!stack_a || !ft_strlen(argv[1]))
		return (&(t_list){NULL, 0, 0, ' ', NULL});
	while (elem[i])
	{
		tmp = ft_lstnew(ft_atoi(elem[i]), main);
		if (!tmp || ft_lstadd_back(&stack_a, &tmp, i + (option == 2)))
			return (free_stack(&stack_a, main));
		i++;
	}
	free_elem(elem, option == 2);
	return (stack_a);
}

int	error_check(char **argv, int argc, t_gen *main)
{
	char	**elem;
	int		i;

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
		if (ft_atol(elem[i], main))
		{
			free_elem(elem, argc == 2);
			return (0);
		}
		i++;
	}
	free_elem(elem, argc == 2);
	return (i - (argc == i));
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_gen		*main;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	main = malloc(sizeof(t_gen));
	if (!main)
		return (0);
	main->offset = 0;
	main->len = error_check(argv, argc, main);
	if (argc <= 1 || !argv || main->len <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	stack_a = create_stacks((argc == 2) + 1, argv, main);
	if (!stack_a->prev && !stack_a->next && !stack_a->index)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	sort_which(&stack_a, &stack_b, main);
	free_stack(&stack_a, main);
	return (0);
}
// int		printlist(t_list **stack, int len, int a_or_b)
// {
// 	int	 i;
// 	t_list  *tmp;

// 	i = 0;
// 	(void)len;
// 	tmp = (*stack);
// 	if (!stack || !*stack)
// 	{
// 		printf("EMPTY STACK\n");
// 		printf("----\n	%c\n", a_or_b);
// 		return (0);
// 	}
// 	do
// 	{
// 		printf("[%zu] %d (%c)\n", tmp->index, tmp->content, tmp->id);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	while (tmp != (*stack));
// 	printf("----\n	%c (%d)\n", a_or_b, a_or_b == 'a');
// 	return (i); r 42 5 2 -o4 -242j
// }