/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:26:48 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/22 20:50:11 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_nod;

	if ((*stack_a) == NULL)
		return ;
	while ((*stack_a)->perv)
		(*stack_a) = (*stack_a)->perv;
	if ((*stack_b) == NULL)
	{
		(*stack_b) = new_node_p((*stack_a)->number, (*stack_a)->position);
		(*stack_a) = (*stack_a)->next;
		if ((*stack_a))
			delete_node((*stack_a)->perv);
	}
	else
	{
		new_nod = new_node_p((*stack_a)->number, (*stack_a)->position);
		add_front(stack_b, new_nod);
		(*stack_a) = (*stack_a)->next;
		if ((*stack_a))
			delete_node((*stack_a)->perv);
	}
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*new_nod;

	if ((*stack_b) == NULL)
		return ;
	while ((*stack_b)->perv)
		(*stack_b) = (*stack_b)->perv;
	if ((*stack_a) == NULL)
	{
		(*stack_a) = new_node_p((*stack_b)->number, (*stack_b)->position);
		(*stack_b) = (*stack_b)->next;
		if ((*stack_b))
			delete_node((*stack_b)->perv);
	}
	else
	{
		new_nod = new_node_p((*stack_b)->number, (*stack_b)->position);
		add_front(stack_a, new_nod);
		(*stack_b) = (*stack_b)->next;
		if ((*stack_b))
			delete_node((*stack_b)->perv);
	}
}

void	sa(t_list **stack_a)
{
	int		tmp;
	int		tmp2;

	get_head(stack_a);
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	while ((*stack_a)->perv)
		(*stack_a) = (*stack_a)->perv;
	tmp = (*stack_a)->next->number;
	tmp2 = (*stack_a)->next->position;
	(*stack_a)->next->number = (*stack_a)->number;
	(*stack_a)->next->position = (*stack_a)->position;
	(*stack_a)->number = tmp;
	(*stack_a)->position = tmp2;
}

void	sb(t_list **stack_b)
{
	int		tmp;
	int		tmp2;

	get_head(stack_b);
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	while ((*stack_b)->perv)
		(*stack_b) = (*stack_b)->perv;
	tmp = (*stack_b)->next->number;
	tmp2 = (*stack_b)->next->position;
	(*stack_b)->next->number = (*stack_b)->number;
	(*stack_b)->next->position = (*stack_b)->position;
	(*stack_b)->number = tmp;
	(*stack_b)->position = tmp2;
}

void	rra(t_list **stack_a)
{
	t_list	*node;

	if (!(*stack_a))
		return ;
	while ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	node = new_node_p((*stack_a)->number, (*stack_a)->position);
	add_front(stack_a, node);
	while ((*stack_a)->next->next)
		(*stack_a) = (*stack_a)->next;
	delete_node((*stack_a)->next);
}
