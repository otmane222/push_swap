/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:12:20 by oaboulgh          #+#    #+#             */
/*   Updated: 2022/10/23 16:19:53 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	sum_of_size_arrays;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	j = ft_strlen(dst);
	if (dstsize < j)
		return (ft_strlen(src) + dstsize);
	else
		sum_of_size_arrays = j + ft_strlen(src);
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (sum_of_size_arrays);
}
