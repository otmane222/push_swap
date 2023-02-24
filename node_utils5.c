/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:38:02 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/24 17:10:04 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list **stack_b, t_list **stack_a)
{
	int		i;

	i = 1;
	get_head(stack_b);
	while ((*stack_b)->next)
	{
		if ((*stack_b)->position < (*stack_b)->next->position)
			(*stack_b) = (*stack_b)->next;
		else if ((*stack_b)->position > (*stack_b)->next->position)
			return (0);
		i++;
	}
	get_head(stack_b);
	while (i--)
		pa(stack_b, stack_a);
	return (1);
}

void	sort_3_continue(t_list **stack_a, t_data *data)
{
	get_head(stack_a);
	data->i = (*stack_a)->position;
	get_tail(stack_a);
	data->index = (*stack_a)->position;
	if (data->i < data->index)
	{
		if ((*stack_a)->perv->position < data->i)
		{
			if ((*stack_a)->perv->position < data->index)
				sa(stack_a);
			else if ((*stack_a)->perv->position > data->index)
			{
				ra(stack_a, 1);
				ra(stack_a, 1);
			}
		}
		else if ((*stack_a)->perv->position > data->i)
		{
			if ((*stack_a)->perv->position > data->index)
			{
				rra(stack_a, 1);
				sa(stack_a);
			}
		}
	}
}

void	sort_3(t_list **stack_a, t_data *data)
{
	get_head(stack_a);
	data->i = (*stack_a)->position;
	get_tail(stack_a);
	data->index = (*stack_a)->position;
	if (data->i > data->index)
	{
		if ((*stack_a)->perv->position < data->i)
		{
			if ((*stack_a)->perv->position < data->index)
				ra(stack_a, 1);
			else if ((*stack_a)->perv->position > data->index)
			{
				sa(stack_a);
				ra(stack_a, 1);
				ra(stack_a, 1);
			}
		}
		else if ((*stack_a)->perv->position > data->i)
		{
			if ((*stack_a)->perv->position > data->index)
				rra(stack_a, 1);
		}
	}
	sort_3_continue(stack_a, data);
}

int	small_help(t_list **stack_a, t_data *data)
{
	int	i;

	i = 0;
	while ((*stack_a)->next)
	{
		if ((*stack_a)->position < data->chunk1)
		{
			data->flag = 5;
			if ((*stack_a)->position < data->chunk2)
			{
				data->flag = 4;
			}
			break ;
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	return (i);
}

int	small_calcul(t_list **stack_a, t_data *data)
{
	int	i;

	i = 0;
	get_head(stack_a);
	if (data->chunk2 > data->chunk1)
	{
		while ((*stack_a)->next)
		{
			if ((*stack_a)->position <= data->chunk2)
			{
				data->flag = 4;
				if ((*stack_a)->position < data->chunk1)
				{
					data->flag = 5;
				}
				break ;
			}
			(*stack_a) = (*stack_a)->next;
			i++;
		}
	}
	else if (data->chunk2 < data->chunk1)
		i = small_help(stack_a, data);
	data->size_ninc = i;
	return (i);
}

void	sort_5(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	i;

	i = 0;
	get_head(stack_a);
	while ((*stack_a)->position)
	{
		if ((*stack_a)->position == 0)
			break ;
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	if (i == 0 || i == 1 || i == 2)
	{
		while (i--)
			ra(stack_a, 1);
	}
	else if (i == 3 || i == 4)
	{
		while (i < 5)
		{
			rra(stack_a, 1);
			i++;
		}
	}
	pb(stack_a, stack_b);
	get_head(stack_a);
	i = 0;
	while ((*stack_a)->position)
	{
		if ((*stack_a)->position == 1)
			break ;
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	if (i == 0 || i == 1 || i == 2)
	{
		while (i--)
			ra(stack_a, 1);
	}
	else if (i == 3)
	{
		while (i < 4)
		{
			rra(stack_a, 1);
			i++;
		}
	}
	pb(stack_a, stack_b);
	sort_3(stack_a, data);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
