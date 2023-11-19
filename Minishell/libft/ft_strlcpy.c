/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:14:09 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 18:33:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		if (dstsize == 1)
			dst[0] = '\0';
		else
		{
			while (src[i] && i <= dstsize - 2)
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
	}
	while (src[i])
		i++;
	return (i);
}
