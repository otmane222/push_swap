/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:27:06 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/23 01:03:11 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrb(t_list **stack_b)
{
	t_list	*node;

	if (!(*stack_b))
		return ;
	while ((*stack_b)->next)
		(*stack_b) = (*stack_b)->next;
	node = new_node_p((*stack_b)->number, (*stack_b)->position);
	add_front(stack_b, node);
	while ((*stack_b)->next->next)
		(*stack_b) = (*stack_b)->next;
	delete_node((*stack_b)->next);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	int		i;

	i = 0;
	if (!(*stack_b))
		i = 1;
	if (i == 0)
	{
		while ((*stack_b)->next)
			(*stack_b) = (*stack_b)->next;
		node = new_node_p((*stack_b)->number, (*stack_b)->position);
		add_front(stack_b, node);
		while ((*stack_b)->next->next)
			(*stack_b) = (*stack_b)->next;
		delete_node((*stack_b)->next);
	}
	rra(stack_a);
}

void	ra(t_list **stack_a)
{
	t_list	*node;

	if (!(*stack_a) || !first_time(stack_a))
		return ;
	get_head(stack_a);
	node = new_node_p((*stack_a)->number, (*stack_a)->position);
	while ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = node;
	node->perv = (*stack_a);
	while ((*stack_a)->perv->perv)
		(*stack_a) = (*stack_a)->perv;
	delete_node((*stack_a)->perv);
}

void	rb(t_list **stack_b)
{
	t_list	*node;

	if (!(*stack_b) || !first_time(stack_b))
		return ;
	get_head(stack_b);
	node = new_node_p((*stack_b)->number, (*stack_b)->position);
	while ((*stack_b)->next)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = node;
	node->perv = (*stack_b);
	while ((*stack_b)->perv->perv)
		(*stack_b) = (*stack_b)->perv;
	delete_node((*stack_b)->perv);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*node;

	i = 0;
	if (!(*stack_b) || !first_time(stack_b))
		i = 1;
	if (i == 0)
	{
		get_head(stack_b);
		node = new_node_p((*stack_b)->number, (*stack_b)->position);
		while ((*stack_b)->next)
			(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = node;
		node->perv = (*stack_b);
		while ((*stack_b)->perv->perv)
			(*stack_b) = (*stack_b)->perv;
		delete_node((*stack_b)->perv);
	}
	ra(stack_a);
}
