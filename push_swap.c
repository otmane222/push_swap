/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:39:40 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/21 21:04:59 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_time(t_list **stack_a)
{
	int	i;

	i = 0;
	get_head(stack_a);
	while ((*stack_a)->next)
	{
		i++;
		(*stack_a) = (*stack_a)->next;
	}
	if (i >= 1)
		return (1);
	else
		return (0);
}

int	check_flag(t_list **stack_a)
{
	get_head(stack_a);
	while ((*stack_a)->next)
	{
		if ((*stack_a)->flag == 1)
			return (0);
		(*stack_a) = (*stack_a)->next;
	}
	return (1);
}

void	put_p2(t_list **stack_a, t_data *data, int tmp)
{
	get_head(stack_a);
	while ((*stack_a)->next)
	{
		if ((*stack_a)->number == tmp && (*stack_a)->flag)
		{
			(*stack_a)->flag = 0;
			(*stack_a)->position = data->i;
			data->i = data->i + 1;
			break ;
		}
		(*stack_a) = (*stack_a)->next;
		if ((*stack_a)->number == tmp && (*stack_a)->flag)
		{
			(*stack_a)->flag = 0;
			(*stack_a)->position = data->i;
			data->i = data->i + 1;
			break ;
		}
	}
}

int	*full_numbers(char **str, t_data *data)
{
	int	*num;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	data->index = j;
	num = malloc(sizeof(int) * j);
	if (!num)
		return (0);
	j = 0;
	data->size = 0;
	full_numbers01(str, num, data);
	return (num);
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
	push_chunks(stack_a, stack_b, data);
	data->better = 0;
	do_it(stack_a, stack_b, data);
	while ((*stack_b))
		get_data_back_sorted(stack_b, stack_a, data);
	return (0);
}
