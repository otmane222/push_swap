/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:23:09 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/23 01:19:33 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_the_instruction(char *str)
{
	int	i;

	i = -1;
	if (ft_strncmp(str, "ra\n", 3) == 0)
		i = 1;
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		i = 2;
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		i = 3;
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		i = 4;
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		i = 5;
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		i = 6;
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		i = 7;
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		i = 8;
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		i = 9;
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		i = 10;
	return (i);
}

void	make_instructions(t_list **stack_a, t_list **stack_b, int i)
{
	if (i == 1)
		ra(stack_a);
	else if (i == 2)
		rb(stack_b);
	else if (i == 3)
		rr(stack_a, stack_b);
	else if (i == 4)
		rra(stack_a);
	else if (i == 5)
		rrb(stack_b);
	else if (i == 6)
		rrr(stack_a, stack_b);
	else if (i == 7)
		sa(stack_a);
	else if (i == 8)
		sb(stack_b);
	else if (i == 9)
		ss(stack_a, stack_b);
	else if (i == 10)
		pa(stack_b, stack_a);
	else if (i == 11)
		pb(stack_a, stack_b);
}

void	check_sort(t_list **stack_a, t_list **stack_b)
{
	int	tmp;

	get_head(stack_a);
	if ((*stack_b) || (!(*stack_a)))
	{
		write (2, "KO\n", 3);
		return ;
	}
	tmp = (*stack_a)->number;
	while ((*stack_a)->next)
	{
		if ((*stack_a)->next->number < tmp)
		{
			write (2, "KO\n", 3);
			return ;
		}
		(*stack_a) = (*stack_a)->next;
		tmp = (*stack_a)->number;
	}
	write (2, "OK\n", 3);
}

void	read_her_doc(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	data->move = 0;
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			return ;
		i = check_the_instruction(str);
		if (ft_strncmp(str, "pb\n", 3) == 0)
			i = 11;
		if (i == -1)
		{
			write (2, "Error\n", 6);
			data->stop = 9;
			break ;
		}
		make_instructions(stack_a, stack_b, i);
		free(str);
	}
	free(str);
	str = NULL;
	printf("%d", i);
}

int	main(int ac, char **av)
{
	t_list		**stack_a;
	t_list		**stack_b;
	t_data		*data;

	if (ac == 1)
		return (0);
	data = malloc (sizeof(t_data));
	if (!data)
		return (1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (1);
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_b)
		return (1);
	initial_vars(stack_a, stack_b, data);
	data->num = read_and_check(av, data);
	list_of_nodes(stack_a, data);
	read_her_doc(stack_a, stack_b, data);
	if (data->stop != 9)
		check_sort(stack_a, stack_b);
	return (0);
}
