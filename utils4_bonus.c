/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:34:56 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/23 07:25:41 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_num(int *num, int j)
{
	int	i;

	i = j;
	j -= 1;
	while (j >= 0)
	{
		if (num[j] == num[i])
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		j--;
	}
}

void	check_error1(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

void	error_found(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

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
