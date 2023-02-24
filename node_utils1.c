/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:42:04 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/23 18:08:59 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_tail(t_list **stack_a)
{
	if (!(*stack_a))
		return ;
	while ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
}

void	start_the_moving_x(t_list **stack_b, t_list **stack_a, t_data *data)
{
	get_head(stack_b);
	while (data->position)
	{
		rb(stack_b, 1);
		data->position--;
	}
	pa(stack_b, stack_a);
	if (data->move == 9)
		ra(stack_a, 1);
}

void	start_the_moving_y(t_list **stack_b, t_list **stack_a, t_data *data)
{
	get_head(stack_b);
	while (data->position < data->pass)
	{
		rrb(stack_b);
		data->position++;
	}
	pa(stack_b, stack_a);
	if (data->move == 9)
		ra(stack_a, 1);
}

void	big_element(t_list **stack_b, t_data *data)
{
	int		tmp;
	int		a;

	a = 0;
	if (!(*stack_b))
		return ;
	tmp = (*stack_b)->position;
	data->move = 0;
	while ((*stack_b)->next)
	{
		if ((*stack_b)->next->position > tmp)
			tmp = (*stack_b)->next->position;
		(*stack_b) = (*stack_b)->next;
	}
	get_head(stack_b);
	while ((*stack_b)->next)
	{
		if ((*stack_b)->position == tmp)
			break ;
		(*stack_b) = (*stack_b)->next;
		a++;
	}
	data->chunk1 = tmp;
	data->position = a;
}

void	get_data_back_sorted(t_list **stack_b, t_list **stack_a, t_data *data)
{
	if (!(*stack_b))
		return ;
	get_head(stack_b);
	data->pass = 1;
	while ((*stack_b)->next)
	{
		(*stack_b) = (*stack_b)->next;
		data->pass++;
	}
	data->flag = data->pass / 2;
	get_head(stack_b);
	data->move = 0;
	data->better = 0;
	big_element(stack_b, data);
	better_element(stack_b, stack_a, data);
	set_up_stack_a(stack_a, stack_b);
	if (data->position < data->flag)
		start_the_moving_x(stack_b, stack_a, data);
	else if (data->position >= data->flag)
		start_the_moving_y(stack_b, stack_a, data);
	set_up_stack_a(stack_a, stack_b);
}
