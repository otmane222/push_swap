/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utilis5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:38:02 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/21 21:04:01 by oaboulgh         ###   ########.fr       */
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

void	sort_4(t_list **stack_a)
{
	int	i;
	int	j;

	get_head(stack_a);
	i = (*stack_a)->position;
	get_tail(stack_a);
	j = (*stack_a)->position;
	if (i > j)
	{
		if (j < (*stack_a)->perv->position)
		{
			if (i < (*stack_a)->perv->position)
				sa(stack_a);
		}
		else if (j > (*stack_a)->perv->position)
		{
			sa(stack_a);
			rra(stack_a, 1);
		}
	}
	else if (i < j)
	{
		if (j < (*stack_a)->perv->position)
		{
			sa(stack_a);
			rra(stack_a, 1);
		}
		else if (j > (*stack_a)->perv->position)
		{
			if (i < (*stack_a)->perv->position)
			{
				rra(stack_a, 1);
				rra(stack_a, 1);
				sa(stack_a);
			}
			else if (i > (*stack_a)->perv->position)
			{
				rra(stack_a, 1);
			}
		}
	}
}

void	sort_3(t_list **stack_a)
{
	int	i;
	int	j;

	get_head(stack_a);
	i = (*stack_a)->position;
	get_tail(stack_a);
	j = (*stack_a)->position;
	if (i > j && i < (*stack_a)->perv->position)
	{
		ra(stack_a, 1);
	}
	else if (i > j && i > (*stack_a)->perv->position)
	{
		sa(stack_a);
		rra(stack_a, 1);
	}
	else if (i < j && i > (*stack_a)->perv->position)
	{
		sa(stack_a);
		rra(stack_a, 1);
	}
	else if (i < j && i < (*stack_a)->perv->position)
	{
		ra(stack_a, 1);
	}
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
	return (i);
}
