/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:45:32 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/22 16:20:30 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
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
	rra(stack_a, 1);
	write (1, "rrr\n", 4);
}

void	ra(t_list **stack_a, int flag)
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
	if (flag == 1)
		write (1, "ra\n", 3);
}

void	rb(t_list **stack_b, int flag)
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
	if (flag == 1)
		write (1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
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
	ra(stack_a, 90);
	write (1, "rr\n", 3);
}
