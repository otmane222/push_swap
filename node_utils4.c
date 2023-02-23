/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utilis4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:00:41 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/21 21:03:12 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	better_element(t_list **stack_b, t_list **stack_a, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	get_head(stack_b);
	get_tail(stack_a);
	j = (*stack_a)->position;
	if (j == data->size - 1)
	{
		data->position = 1;
		data->move = 9;
		return ;
	}
	else if ((*stack_a)->position != data->size - 1)
	{
		while ((*stack_b)->next)
		{
			if ((*stack_b)->position == j + 1)
				break ;
			(*stack_b) = (*stack_b)->next;
			i++;
		}
	}
	data->better = i;
	calcul(data);
}

void	calcul(t_data *data)
{
	int	k;
	int	m;

	if (data->position >= data->flag)
		k = data->position - data->flag;
	else
		k = data->flag - data->position;
	if (data->better >= data->flag)
		m = data->better - data->flag;
	else
		m = data->flag - data->position;
	if (k >= m)
		data->position = data->position;
	else if (m > k)
	{
		data->position = data->better;
		data->move = 9;
	}
}

void	set_up_stack_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		t;

	t = 0;
	if ((!*stack_a))
		return ;
	get_head(stack_b);
	while (1)
	{
		get_head(stack_a);
		i = (*stack_a)->position;
		get_tail(stack_a);
		j = (*stack_a)->position;
		if (i == j + 1)
			rra(stack_a, 1);
		else
			break ;
	}
}

void	do_it(t_list **stack_a, t_list **stack_b, t_data *data)
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
	data->position = a;
	start_the_moving_x(stack_b, stack_a, data);
}

void	sort_2(t_list **stack_a)
{
	get_head(stack_a);
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	if ((*stack_a)->position > (*stack_a)->next->position)
		sa(stack_a);
	else
		return ;
}
