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
#include "libft.h"
/*
*	Funcction: Conatenate 2 strings. Fills in destination the source str.
*				No malloc is executed.
*	Parameters:	char *destination
*				char *source
*				length
*	Returns: the total lentgh of the resultant string.
*/
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
	else if (!lendst && !size)
		return (lensrc);
	else
		res = lendst + lensrc;
	i = lendst;
	while (i < size - 1 && src[i - lendst])
	{
		*(char *)(dst + i) = *(char *)(src + i - lendst);
		i++;
	}
	*(char *)(dst + i) = '\0';
	return (res);
}
