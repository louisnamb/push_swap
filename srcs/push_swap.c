/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:37:09 by lnambaji          #+#    #+#             */
/*   Updated: 2023/11/21 15:28:09 by lnambaji         ###   ########.fr       */
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
        return (0);
	}
    do
    {
		printf("[%zu] %d (%c)\n", tmp->index, tmp->content, tmp->id);
        i++;
        tmp = tmp->next;
    }
	while (tmp != (*stack));
	printf("----\n    %c (%d)\n", a_or_b, a_or_b == 'a');
	return (i);
}

t_list	*create_stacks(int option, char **argv, t_gen *main)
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
       return (&(t_list){NULL, 0, 0, ' ', 0, NULL});
    if (option == 2)
	{
		i = 0;
		elem = ft_split(argv[1], ' ');
	}
    else
        elem = argv;
    stack_a->content = ft_atoi(elem[i++]);
	stack_a->index = 1;
	stack_a->id = 'a';
    while (elem[i])
	{
		tmp = ft_lstnew(ft_atoi(elem[i]), main);
        if (!tmp || ft_lstadd_back(&stack_a, tmp, i + (option == 2)))
		{
			free_stack(&stack_a);
			return (&(t_list){NULL, 0, 0, ' ', 0, NULL});
		}
		tmp = NULL;
		i++;
	}
    return (stack_a);
}

int	skip_whitespaces(int c)
{
	int	is;

	is = (c == ' ' || c == '\t' || c == '\v');
	return (is || c == '\r' || c == '\f');
}

int	check_num(long num, int sign, int digit)
{
	if (sign == -1)
		return (((num * -1) <= INT_MIN / 10) && ((digit * sign) < INT_MIN % 10));
	else
		return (num >= INT_MAX / 10 && digit > INT_MAX % 10);
}

int	ft_atol(char	*str, t_gen *main)
{
	int		i;
	long	num;
	int		sign;
	int	digit;

	sign = 1;
	i = 0;
	num = 0;
	while (skip_whitespaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if ((str[i]) == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (check_num(num, sign, digit))
				return (1);
			num *= 10 + digit;
		}
		else if (skip_whitespaces(str[i]))
			break ;
		else
			return (1);
		i++;
	}
	if (sign == -1 && main->offset < (num * sign))
		main->offset = num * sign;
	else
		main->offset = 0;
	return (0);
}

int		error_check(char **argv, int argc, t_gen *main)
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
			return (0);
		i++;
	}
	return (i - (argc == i));
}

int main(int argc, char **argv)
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
	if (argc <= 1 || !argv)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	if (main->len)
	{
		stack_a = create_stacks((argc == 2) + 1, argv, main);
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

/*
Evaluate the indexes of the numbers if they were already sorted and then sort based on that.
e.g., ./push_swap 1000000 1 2 500 because 4 1 2 3. this lessens the number of iterations you do
*/