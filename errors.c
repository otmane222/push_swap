/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:19:40 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/10 15:25:24 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_num(int *num, int j)
{
	int	i;

	i = j;
	j -= 1;
	while (j >= 0)
	{
		if (num[j] == num[i])
		{
			write (2, "Error", 5);
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
			write (2, "Error", 5);
			exit (1);
		}
		i++;
	}
}

void	error_found(void)
{
	write (2, "Error", 5);
	exit (1);
}
