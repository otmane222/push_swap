/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utilis2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:01:37 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/21 21:02:05 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_best_move(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int		i;

	i = 0;
	data->flag = 0;
	data->better = 0;
	i = small_calcul(stack_a, data);
	while (i && (data->flag == 4 || data->flag == 5))
	{
		ra(stack_a, 1);
		i--;
	}
	pb(stack_a, stack_b);
	if (data->flag == 5)
	{
		get_head(stack_a);
		if ((*stack_a)->position > data->chunk2)
			rr(stack_a, stack_b);
		else
			rb(stack_b, 1);
	}
}

void	push_chunks(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int		i;
	int		j;
	int		tmp;
	int		k;

	i = 0;
	k = 0;
	while (data->chunk1 <= data->size)
	{
		j = data->chunk1;
		tmp = data->chunk2;
		while (1)
		{
			get_head(stack_a);
			get_best_move(stack_a, stack_b, data);
			if (check_position(stack_a, data->chunk1))
				data->chunk1 += data->var_split_chunk * 2;
			if (check_position(stack_a, data->chunk2))
				data->chunk2 += data->var_split_chunk * 2;
			if (check_position(stack_a, j) && check_position(stack_a, tmp))
				break ;
		}
	}
	get_head(stack_a);
	while ((*stack_a)->next)
	{
		i++;
		(*stack_a) = (*stack_a)->next;
	}
	while (i >= 0)
	{
		pb(stack_a, stack_b);
		i--;
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
	split_chunks(data);
}
