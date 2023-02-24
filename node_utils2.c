/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:01:37 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/24 19:31:20 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_best_move(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (data->position)
	{
		ra(stack_a, 1);
		data->position--;
	}
	pb(stack_a, stack_b);
	if (data->flag == 4)
	{
		if ((*stack_a)->position > data->chunk2)
			rr(stack_a, stack_b);
		else
			rb(stack_b, 1);
	}
}

void	get_best_move(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->flag = 0;
	data->better = 0;
	data->pass = 0;
	data->k = 0;
	data->move = 0;
	get_head(stack_a);
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		data->pass++;
	}
	data->k = data->pass / 2;
	data->position = small_calcul(stack_a, data);
	check_best_move(stack_a, stack_b, data);
}

void	push_chunks(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (data->size <= 5 && data->size != 4)
	{
		if (data->size == 3)
		{
			sort_3(stack_a, data);
		}
		else
			sort_5(stack_a, stack_b, data);
		return ;
	}
	while (data->chunk1 <= data->size)
	{
		data->j = data->chunk1;
		data->i = data->chunk2;
		while (1)
		{
			get_best_move(stack_a, stack_b, data);
			if (check_p(stack_a, data->j) && check_p(stack_a, data->i))
				break ;
		}
		data->chunk1 += data->var_split_chunk * 2;
		data->chunk2 += data->var_split_chunk * 2;
	}
	push_rest(stack_a, stack_b);
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
