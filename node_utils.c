/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:38:59 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/17 22:41:44 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int x)
{
	t_list	*new_nod;

	new_nod = malloc(sizeof(t_list));
	if (!new_nod)
		return (NULL);
	new_nod->number = x;
	new_nod->flag = 1;
	new_nod->next = NULL;
	new_nod->perv = NULL;
	return (new_nod);
}

t_list	*new_node_p(int x, int y)
{
	t_list	*new_nod;

	new_nod = malloc(sizeof(t_list));
	if (!new_nod)
		return (NULL);
	new_nod->number = x;
	new_nod->position = y;
	new_nod->flag = 1;
	new_nod->next = NULL;
	new_nod->perv = NULL;
	return (new_nod);
}

void	add_front(t_list **head, t_list *node)
{
	while ((*head)->perv)
			(*head) = (*head)->perv;
	node->next = (*head);
	(*head)->perv = node;
	(*head) = node;
	node->perv = NULL;
}

void	delete_node(t_list *node)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (node->next && !node->perv)
	{
		tmp = node->next;
		tmp->perv = NULL;
	}
	else if (!node->next && node->perv)
	{
		tmp2 = node->perv;
		tmp2->next = NULL;
	}
	else if (node->next && node->perv)
	{
		tmp = node->next;
		tmp2 = node->perv;
		tmp->perv = tmp2;
		tmp2->next = tmp;
	}
	free(node);
	node = NULL;
}

void	get_head(t_list **stack_a)
{
	if (!(*stack_a))
		return ;
	while ((*stack_a)->perv)
		(*stack_a) = (*stack_a)->perv;
}
