/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utilis3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:08:55 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/21 21:02:26 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_chunks(t_data *data)
{
	int		i;

	i = chunks_per_size(data);
	data->var_split_chunk = data->size / i;
	data->chunk2 = data->var_split_chunk * 2;
	data->chunk1 = data->var_split_chunk;
}

void	initial_vars(t_list **stack_a, t_list **stack_b, t_data *data)
{
	(*stack_a) = NULL;
	(*stack_b) = NULL;
	data->index = 20;
	data->i = 0;
	data->position = 0;
	data->flag = 1;
	data->move = 0;
	data->size = 0;
	data->pass = 1;
	data->better = 0;
	data->first = 0;
}

int	check_position(t_list **stack_a, int chunk)
{
	int	i;

	i = 0;
	get_head(stack_a);
	while ((*stack_a)->next)
	{
		if ((*stack_a)->position <= chunk)
			return (0);
		(*stack_a) = (*stack_a)->next;
	}
	return (1);
}

void	check_stack_a(t_list **stack_a)
{
	int	i;
	int	j;

	if (!(*stack_a))
		return ;
	get_head(stack_a);
	i = (*stack_a)->position;
	get_tail(stack_a);
	j = (*stack_a)->position;
	if ((j - 1) == i)
		rra(stack_a, 1);
}

int	chunks_per_size(t_data *data)
{
	int		i;

	i = 5;
	if (data->size >= 400)
		i = 16;
	else if (data->size > 60)
		i = 8;
	else if (data->size <= 60)
		i = 1;
	return (i);
}
