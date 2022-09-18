/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:11:26 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/18 19:17:50 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (!dst || !src)
		return (NULL);
	if (dst == src || !len)
		return (dst);
	if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			*(char*) (dst+i) = *(char*)(src+i);
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
