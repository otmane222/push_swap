/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:31:03 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/22 17:51:24 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	*full_numbers(char **str, t_data *data)
{
	int	*num;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	data->index = j;
	num = malloc(sizeof(int) * j);
	if (!num)
		return (0);
	j = 0;
	data->size = 0;
	full_numbers01(str, num, data);
	return (num);
}
