/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:09:25 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/20 19:49:44 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handler_long_atoi(unsigned int n, unsigned int o)
{
	if ((n / 10) == o)
		return (0);
	return (1);
}

static int	rtn_atoi(unsigned int res, int sign, const char *str)
{
	unsigned int	old_res;

	while (*str >= '0' && *str <= '9')
	{
		old_res = res;
		res = res * 10 + (*str - '0');
		if (handler_long_atoi(res, old_res) == 0)
			str++;
		if (res >= 2147483648)
		{
			if (res == 2147483648 && sign < 0)
				break ;
			write (2, "Error\n", 6);
			exit (1);
		}
		else if (handler_long_atoi(res, old_res) == 1 || res >= 2147483648)
		{
			write (2, "Error\n", 6);
			exit (1);
		}
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	unsigned int		res;
	int					sign;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	return (rtn_atoi(res, sign, str) * sign);
}
