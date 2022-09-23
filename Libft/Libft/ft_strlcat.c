/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:13:57 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 19:05:21 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include"libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (!src || !size || size < lendst)
		return (lendst + lensrc - 1);
	i = 0;
	while (i < size - 1 - lendst && src[i])
	{
		*(char*)(dst + lendst + i) = *(char*)(src + i);
		i++;
	}
	*(char*)(dst + lendst + i) = '\0';
	return (lendst + lensrc );
}
