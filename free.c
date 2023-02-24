/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:41 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/24 19:59:38 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **s, size_t i)
{
	while (s[i] != NULL)
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

void	free_data(t_data *data)
{
	free(data->num);
	free(data);
}

int	sorted(t_list **stack_a)
{
	int	tmp;

	get_head(stack_a);
	tmp = (*stack_a)->position;
	while ((*stack_a)->next)
	{
		if ((*stack_a)->next->position < tmp)
			break ;
		(*stack_a) = (*stack_a)->next;
		tmp = (*stack_a)->position;
	}
	if (!(*stack_a)->next)
		return (1);
	return (0);
}
