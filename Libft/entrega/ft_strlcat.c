/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:13:57 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 10:02:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	res;	
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen (dst);
	lensrc = ft_strlen (src);
	if (size < lendst)
		return (lensrc + size);
	else
		res = lendst + lensrc;
	i = 0;
	while (i < size - 1 - lendst && src[i])
	{
		*(char *)(dst + lendst + i) = *(char *)(src + i);
		i++;
	}
	*(char *)(dst + lendst + i) = '\0';
	return (res);
}
