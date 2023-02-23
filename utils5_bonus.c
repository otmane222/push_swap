/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:45:22 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/23 01:03:20 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	list_of_nodes(t_list **head, t_data *data)
{
	int		i;
	t_list	*tmp2;

	i = 0;
	if (*head == NULL)
		(*head) = new_node(data->num[i]);
	i++;
	while (i < data->size)
	{
		tmp2 = new_node(data->num[i]);
		(*head)->next = tmp2;
		tmp2->perv = (*head);
		(*head) = (*head)->next;
		i++;
	}
	i = 0;
	while (i < data->size)
	{
		put_positions(head, data);
		i++;
	}
}

void	put_positions(t_list **stack_a, t_data *data)
{
	int			tmp;

	get_head(stack_a);
	while ((*stack_a)->next)
	{
		if ((*stack_a)->flag)
		{
			tmp = (*stack_a)->number;
			break ;
		}
		(*stack_a) = (*stack_a)->next;
	}
	if ((*stack_a)->flag)
		tmp = (*stack_a)->number;
	get_head(stack_a);
	while ((*stack_a)->next)
	{
		if (tmp > (*stack_a)->next->number && (*stack_a)->next->flag == 1)
			tmp = (*stack_a)->next->number;
		(*stack_a) = (*stack_a)->next;
	}
	put_p2(stack_a, data, tmp);
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

void	ss(t_list **stack_a, t_list **stack_b)
{
	int		tmp;
	int		tmp2;
	int		i;

	i = 0;
	get_head(stack_a);
	if (!(*stack_a) || !(*stack_a)->next)
		i = 1;
	if (i == 0)
	{
		while ((*stack_a)->perv)
			(*stack_a) = (*stack_a)->perv;
		tmp = (*stack_a)->next->number;
		tmp2 = (*stack_a)->next->position;
		(*stack_a)->next->number = (*stack_a)->number;
		(*stack_a)->next->position = (*stack_a)->position;
		(*stack_a)->number = tmp;
		(*stack_a)->position = tmp2;
	}
	sb(stack_b);
}

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
