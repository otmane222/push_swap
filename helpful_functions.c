/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:02:01 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/22 19:02:47 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_numbers01(char **str, int *num, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9') && str[i][j])
			{
				if ((j == 0 && (str[i][j] == '-' || str[i][j] == '+') \
				&& str[i][j + 1]))
					j = j + 1 -1;
				else
					error_found();
			}
			j++;
		}
		num[i] = ft_atoi((const char *)str[i]);
		data->size = data->size + 1;
		check_num(num, i);
		i++;
	}
}

int	*read_and_check(char **av, t_data *data)
{
	int		i;
	int		j;
	char	*str;
	int		*num;
	char	**stor;

	i = 1;
	data->flag = 1;
	str = ft_strdup("");
	while (av[i])
	{
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	i = 1;
	j = 0;
	stor = ft_split(str, ' ');
	check_error1(av);
	num = full_numbers(stor, data);
	free_all(stor, 0);
	return (num);
}

void	ss(t_list **stack_a, t_list **stack_b)
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
	sb(stack_b, 0);
	write (1, "ss\n", 3);
}
