/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:11:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/18 19:50:34 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	
	i = 0;
	if (!dst)
		return (NULL);
	while (i < n)
	{
		*(char*)(dst+i) = *(char*)(src+i);
		i++;
	}
	return (dst);
}
